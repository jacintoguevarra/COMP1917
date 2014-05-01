#include <stdio.h>
#include <stdlib.h>
#define MAX_ITERATIONS 256

double x= -2;
double y= 2;
int overall = 0;
int count =0;
int escapeSteps(double x, double y);
int main(int argc, char *argv[]){
while(overall<80){

        count = 0;
        x= -2;
    while( count < 80 ){
            if (( escapeSteps(x,y) == 256)){
               printf("*");
            }
           else{
            printf(" ");
           }

           x+= 0.05;
           count ++;

        }
   overall++;
   y-=0.05;
   printf("\n");
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



