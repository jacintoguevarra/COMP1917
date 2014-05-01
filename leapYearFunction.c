//  isLeapYear.c
//
//  Created by Jacinto Guevarra Churches on 18/03/2014.
//  Copyright (c) 2014 Jacinto Guevarra Churches. All rights reserved.
//

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#define START_OF_GREG_CALENDAR 1582

int isLeapYear(int year);

int year;

int main (int argc, const char * argv[]) {

    isLeapYear(year);
        
    return EXIT_SUCCESS;
}

int isLeapYear(int year){
        
    printf ("Please enter the year you are interested in after 1582\n");
                     
    scanf("%d", &year);

    printf("%d ", year);
                     
    if ((year % 400) == 0){
        
        printf("is a leap year!\n");
    } else if ((year % 4) == 0) {
            if (year % 100 == 0) {
                printf("is not a leap year!\n");
            } else {
                printf ("is a leap year!\n");
            }
        } else {
            printf ("is not a leap year\n");
     
  }

    return year;
}