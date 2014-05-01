/*
 *  pixelColor.h
 *  mandelbrot colors
 *
 *  Created by Richard Buckland on 13/04/11.
 *  Licensed under Creative Commons SA-BY-NC 3.0.  
 *
 */
#include "pixelColor.h"
 
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

	intensity = (steps*50)/256;

	return intensity;
