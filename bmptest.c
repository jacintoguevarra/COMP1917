//bmp printing

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#define MAX_ITERATIONS 255


double escapeSteps (double x, double y);

int main(int argc, char * argv[]){


/*bmp[54 + (512*512*3)]=
		{0x42,0x4d,0x36,0x00,0x0c,0x00,0x00,0x00,0x00,0x00,0x36,0x00,0x00,0x00,0x28,0x00,0x00
		,0x00,0x00,0x02,0x00,0x00,0x00,0x02,0x00,0x00,0x01,0x00,0x18,0x00,0x00,0x00,0x00,0x00
		,0x00,0x00,0x0c,0x00,0x13,0x0b,0x00,0x00,0x13,0x0b,0x00,0x00,0x00,0x00,0x00,0x00,0x00
		,0x00,0x00,0x00};
	    */
int i;

int bmp [i];	

int count;

count = 0;    

int steps = escapeSteps();

while(count < 512*512*3){
	int i = 55;
	bmp[i] = pixelColour (mandelbrot());

	count++;
	}

return EXIT_SUCCESS;
}


double escapeSteps (double x, double y){
	scanf ("%d %d", double x, double y);

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