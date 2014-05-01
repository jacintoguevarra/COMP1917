//  isLeapYear.c
//
//  Created by Jacinto Guevarra Churches on 18/03/2014.
//  Copyright (c) 2014 Jacinto Guevarra Churches. All rights reserved.
//

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#define START_OF_GREG_CALENDAR = 1582

int isLeapYear(int leapYear);

int main (int argc, const char * argv[]) {
    
  isLeapYear(leapyear);
        
    return EXIT_SUCCESS;
}

    int isLeapYear(int leapYear); {
        
    printf ("Please enter the year you are interested in after 1582\n");
                     
    scanf("%d", &leapYear);
                     
    assert (leapYear >= 1582) ;
                     
                     
    if ((leapYear % 400) == 0){
                         
    leapYear = 1;
        
    } else {
        
        if ((leapYear % 100) == 0)
            if ((leapYear % 4) == 0)
   
                leapYear = 0;

             } /* else {
        
        if ((leapYear % 4) == 0)

        leapYear = 1;
             } else {
                 leapYear = 0;
             } */
  
        

                     
                     return leapYear;
    } }