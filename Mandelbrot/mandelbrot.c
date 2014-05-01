/*
 *  mandelbrotServer.c
 *  Serve the mandelbrot set bmp into a webpage
 *
 *  Created by Tim Lambert on 02/04/12.
 *  Containing code created by Richard Buckland on 28/01/11.
 *  Copyright 2012 Licensed under Creative Commons SA-BY-NC 3.0. 
 *
 *  Edited By Jacinto Guevarra Churches and Ryan Tipping on 18/4/14
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <netinet/in.h>
#include <string.h>
#include <assert.h>
#include <unistd.h>
#include <math.h> 
//#include "pixelColor.c"
//#include "mandelbrot.h"



unsigned char stepsToRed (int steps);
unsigned char stepsToBlue (int steps);
unsigned char stepsToGreen (int steps);

static void serveHTML (int socket);
int waitForConnection (int serverSocket);
int makeServerSocket (int portno);
void serveBMP (int socket, float centrex, float centrey, float z);
 
#define SIMPLE_SERVER_VERSION 1.0
#define REQUEST_BUFFER_SIZE 1000
#define DEFAULT_PORT 1917
#define NUMBER_OF_PAGES_TO_SERVE 10
#define MAX_ITERATIONS 256
// after serving this many pages the server will halt
 
int main (int argc, char *argv[]) {
      
   printf ("************************************\n");
   printf ("Starting simple server %f\n", SIMPLE_SERVER_VERSION);
   printf ("Serving bmps since 2012\n");   
   
   int serverSocket = makeServerSocket (DEFAULT_PORT);   
   printf ("Access this server at http://localhost:%d/\n", DEFAULT_PORT);
   printf ("************************************\n");
   
   char request[REQUEST_BUFFER_SIZE];
   
   int numberServed = 0;
   while (numberServed < NUMBER_OF_PAGES_TO_SERVE) {
      
      printf ("*** So far served %d pages ***\n", numberServed);
      
      int connectionSocket = waitForConnection (serverSocket);
      // wait for a request to be sent from a web browser, open a new
      // connection for this conversation
      
      // read the first line of the request sent by the browser  
      int bytesRead;
      bytesRead = read (connectionSocket, request, (sizeof request)-1);
      assert (bytesRead >= 0); 
      // were we able to read any data from the connection?
            
      // print entire request to the console 
      printf (" *** Received http request ***\n %s\n", request);
      
      double centrex = 0;
      double centrey = 0;
      double z = 0;
      sscanf(request," GET /tile_x%lf_y%lf_z%lf.bmp",&centrex,&centrey,&z);
      
      printf("\ncentrex=%lf centrey=%lf z=%lf", centrex, centrey, z);
    
      if( (centrex == 0.0) && (centrey= 0.0) && (z= 0.0)){
	     serveHTML(connectionSocket);
      }else{
	    serveBMP(connectionSocket,centrex, centrey, z);
      }	
    
      
      
      //send the browser a simple html page using http
      printf (" *** Sending http response ***\n");
      
      // close the connection after sending the page- keep aust beautiful
      close(connectionSocket);
      
      numberServed++;
   } 
   
   // close the server connection after we are done- keep aust beautiful
   printf ("** shutting down the server **\n");
   close (serverSocket);
   
   return EXIT_SUCCESS; 
}
 
void serveBMP (int socket, float centrex, float centrey, float z) {
   char* message;
   
   // first send the http response header
   
   // (if you write stings one after another like this on separate
   // lines the c compiler kindly joins them togther for you into
   // one long string)

  
   message = "HTTP/1.0 200 OK\r\n"
                "Content-Type: image/bmp\r\n"
                "\r\n";        

   printf ("about to send=> %s\n", message);
   write (socket, message, strlen (message));

   
   // now send the BMP
   unsigned char header [54] = {
     0x42,0x4d,0x36,0x00,0x0c,0x00,0x00,0x00,0x00,0x00,0x36,0x00,0x00,0x00,0x28,0x00,0x00 ,0x00,0x00,0x02,0x00,0x00,0x00,0x02,0x00,0x00,0x01,0x00,0x18,0x00,0x00,0x00,0x00,0x00 ,0x00,0x00,0x0c,0x00,0x13,0x0b,0x00,0x00,0x13,0x0b,0x00,0x00,0x00,0x00,0x00,0x00,0x00 ,0x00,0x00,0x00};
 
 
   write (socket, header, sizeof(header));

   unsigned char bmp [512*512*3];

    
  int i = 0;
  double x= 0;
  double y= 0;
  int row = 0;
  int col = 0;
  double zoom = pow(2,-z);
  int escapeSteps (double x, double y);

   y = centrey + 255*zoom;

   while(row < 512){

       col = 0;
        
       
       x = centrex -255*zoom;

	while( col < 512){
       bmp[3*i] = stepsToRed(escapeSteps(x,y));
	   bmp[3*i+1] = stepsToBlue(escapeSteps(x,y));
	   bmp[3*i+2] = stepsToGreen(escapeSteps(x,y));
        i ++;
        x += zoom;      
       //zoom;            
        col ++;
        }

    row++;       
    y -= zoom;
  }
 
	  
//http://localhost:1917/

  

    write (socket, bmp, sizeof(bmp));
}
  
// start the server listening on the specified port number
int makeServerSocket (int portNumber) { 
   
   // create socket
   int serverSocket = socket (AF_INET, SOCK_STREAM, 0);
   assert (serverSocket >= 0);   
   // error opening socket
   
   // bind socket to listening port
   struct sockaddr_in serverAddress;
   bzero ((char *) &serverAddress, sizeof (serverAddress));
   
   serverAddress.sin_family      = AF_INET;
   serverAddress.sin_addr.s_addr = INADDR_ANY;
   serverAddress.sin_port        = htons (portNumber);
   
   // let the server start immediately after a previous shutdown
   int optionValue = 1;
   setsockopt (
      serverSocket,
      SOL_SOCKET,
      SO_REUSEADDR,
      &optionValue, 
      sizeof(int)
   );
 
   int bindSuccess = 
      bind (
         serverSocket, 
         (struct sockaddr *) &serverAddress,
         sizeof (serverAddress)
      );
   
   assert (bindSuccess >= 0);
   // if this assert fails wait a short while to let the operating 
   // system clear the port before trying again
   
   return serverSocket;
}

 
// wait for a browser to request a connection,
// returns the socket on which the conversation will take place
int waitForConnection (int serverSocket) {
   // listen for a connection
   const int serverMaxBacklog = 10;
   listen (serverSocket, serverMaxBacklog);
   
   // accept the connection
   struct sockaddr_in clientAddress;
   socklen_t clientLen = sizeof (clientAddress);
   int connectionSocket = 
      accept (
         serverSocket, 
         (struct sockaddr *) &clientAddress, 
         &clientLen
      );
   
   assert (connectionSocket >= 0);
   // error on accept
   
   return (connectionSocket);
}
    static void serveHTML (int socket) {
    char* message;
    //first send the http response header
    message =
    "HTTP/1.0 200 Found\n"
    "Content-Type: text/html\n"
    "\n";
    printf ("about to send=> %s\n", message);
    write (socket, message, strlen (message));
    message =
    "<!DOCTYPE html>\n"
    "<script src=\"http://almondbread.cse.unsw.edu.au/tiles.js\"></script>"
    "\n";
    write (socket, message, strlen (message));
  }

int escapeSteps (double x, double y){

//xn = xn+1 + c
    double xn = 0;
    double yn = 0;
    int iterations = 0;
    double temp = 0;
 while( ((xn*xn + yn*yn) < 4) && (iterations < MAX_ITERATIONS)){
           temp = (xn*xn) - (yn*yn) + x;
           yn = 2*xn*yn + y;
           xn = temp;
           iterations = iterations + 1;
    }
return iterations;
}

unsigned char intensity;

unsigned char stepsToRed (steps){

	int intensity;

	intensity = (steps*6)%256;

	return intensity;

}

unsigned char stepsToBlue (steps){

	intensity = (steps*20)/256;

	return intensity;
}

unsigned char stepsToGreen (steps){

	intensity = (steps*15)/256;

	return intensity;
}

