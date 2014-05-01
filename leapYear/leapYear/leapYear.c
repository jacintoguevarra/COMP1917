//  leapYear.c
//  Created by Jacinto Guevarra Churches on 16/03/2014
//

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#define START_OF_GREG_CALENDAR = 1582

int main (int argc, const char * argv[]) {
    
    int year ;
    
    printf ("Please enter the year you are interested in\n");
    
    scanf("%d", &year);
    
    assert (year >= 1582) ;
    
    printf("%d ",year );
    
    if ((year % 400) == 0){
        
        printf("is a leap year!\n");
    } else {
        if ((year % 4) == 0) {
            if (year % 100 == 0) {
                printf("is not a leap year!\n");
            } else {
                printf ("is a leap year!\n");
            }
        } else {
            printf ("is not a leap year\n");
        }
        
        }
    
    return EXIT_SUCCESS;  
}
