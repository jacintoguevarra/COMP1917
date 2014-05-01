#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_ITERATIONS 256

int main(int argc, char* argv[]){

double x= -3;
double y= 3;
int overall = 0;
int count =0;
//int zoom= 0;
int escapeSteps(double x, double y);
int BlackOrWhite;



while(overall< 512){

        count = 0;
        x= -3;
    while( count < 512*3 ){
            if (( escapeSteps(x,y) == 256)){
               BlackOrWhite = 256;
            }
           else{
              BlackOrWhite = 0;
           }

           printf("%d", BlackOrWhite);
           x += 0.0005;
           count ++;
    }

   overall++;
   y -= 3;
}
return EXIT_SUCCESS;

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



