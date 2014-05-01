/*
 *  pixelColor.h
 *  mandelbrot colors
 *
 *  Created by Richard Buckland on 13/04/11.
 *  Licensed under Creative Commons SA-BY-NC 3.0.  
 *
 */
 
unsigned char stepsToRed (int steps);
unsigned char stepsToBlue (int steps);
unsigned char stepsToGreen (int steps);

typedef struct _colour {

	int red;

	int blue;

	int green;

} colour;

int red = stepsToRed (steps);

int blue = stepsToBlue (steps);

int green = stepsToGreen (steps);

char stepsToRed (steps){

	int intensity;

	intensity = (steps*3)%4;

	return intensity;

}

char stepsToBlue (steps){

	intensity = (steps*3)%4;

	return intensity;
}

char stepsToGreen (steps){

	intensity = (steps*3)%4;

	return intensity;
}