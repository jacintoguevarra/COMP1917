/*
 *  doomsday.c
 *  A program to test a function dayOfWeek which determines which
 *  day of the week a particular date falls on.
 *  (only for dates after the start of the Gregorian calendar).
 *
 *  Program stub created by Richard Buckland on 17/03/14
 *  This program by YOUR-NAME-HERE
 *  Freely licensed under Creative Commons CC-BY-3.0
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define THURSDAY 0
#define FRIDAY   1
#define SATURDAY 2
#define SUNDAY   3
#define MONDAY   4
#define TUESDAY  5
#define WEDNESDAY 6

#define TRUE 1
#define FALSE 0
#define DAYS_PER_WEEK 7

int dayOfWeek (int doomsday, int leapYear, int month, int day);

int main (int argc, char *argv[]) {
    assert (dayOfWeek (THURSDAY,  FALSE,  4,  4) == THURSDAY);
    assert (dayOfWeek (FRIDAY,    FALSE,  6,  6) == FRIDAY);
    assert (dayOfWeek (MONDAY,    FALSE,  8,  8) == MONDAY);
    assert (dayOfWeek (WEDNESDAY, FALSE, 10, 10) == WEDNESDAY);
    assert (dayOfWeek (FRIDAY,    FALSE, 12, 12) == FRIDAY);
    assert (dayOfWeek (THURSDAY,  FALSE,  9,  5) == THURSDAY);
    assert (dayOfWeek (FRIDAY,    FALSE,  5,  9) == FRIDAY);
    assert (dayOfWeek (SUNDAY,    FALSE,  7, 11) == SUNDAY);
    assert (dayOfWeek (TUESDAY,   FALSE, 11,  7) == TUESDAY);
    assert (dayOfWeek (WEDNESDAY, FALSE,  3,  7) == WEDNESDAY);
    
    assert (dayOfWeek (THURSDAY,  FALSE,  4,  5) == FRIDAY);
    assert (dayOfWeek (SATURDAY,  FALSE,  6,  5) == FRIDAY);
    assert (dayOfWeek (MONDAY,    FALSE,  8,  9) == TUESDAY);
    assert (dayOfWeek (WEDNESDAY, FALSE, 10,  9) == TUESDAY);
    assert (dayOfWeek (FRIDAY,    FALSE, 12, 20) == SATURDAY);
    assert (dayOfWeek (THURSDAY,  FALSE,  9,  9) == MONDAY);
    assert (dayOfWeek (FRIDAY,    FALSE,  5,  5) == MONDAY);
    assert (dayOfWeek (SUNDAY,    FALSE,  7,  7) == WEDNESDAY);
    assert (dayOfWeek (TUESDAY,   FALSE, 11, 11) == SATURDAY);
    assert (dayOfWeek (THURSDAY,  FALSE,  3, 30) == SATURDAY); */
    
    assert (dayOfWeek (TUESDAY,   FALSE,  2,  28) == TUESDAY);
    assert (dayOfWeek (TUESDAY,   FALSE,  2,  27) == MONDAY);
    /* assert (dayOfWeek (THURSDAY,  FALSE,  1,  3)  == THURSDAY);
    
    assert (dayOfWeek (MONDAY, TRUE, 2, 11) == THURSDAY);
    assert (dayOfWeek (SATURDAY, TRUE, 2, 7) == FRIDAY);
    assert (dayOfWeek (SATURDAY, TRUE, 1, 26) == SUNDAY);
    assert (dayOfWeek (MONDAY, TRUE, 1, 17) == SUNDAY); */
    
    
    
    
    printf ("all tests passed - You are awesome!\n");
    return EXIT_SUCCESS;
}


// given the doomsday for a year, and whether or not it is a
// leap year, this function return the day of the week for any
// given month and day in the year.

int dayOfWeek (int doomsday, int leapYear, int month, int day) {
    int answer = 0;
    
    
    if (month%2 == 0) {
        
        if (month == 2 && leapYear == FALSE) {
            answer = day%7 + doomsday;
        }
        else if (month == 2 && leapYear == TRUE) {
            answer = ((day + 14) - 8)%7 + doomsday;
        }
        else {
            answer = ((day + 14) - month)%7 + doomsday;
        }
    }
    
    if (month == 1) {
        if (leapYear == FALSE) {
            answer = ((day + 14) - 10)%7 + doomsday;
        }
        else {
            answer = ((day +14) - 11)%7 + doomsday;
        }
    }
    
    if (month == 3 || month == 11) {
        answer = (day+7)%7 + doomsday;
    }
    
    if (month == 5) {
        answer = ((day + 14) - 9)%7 + doomsday;
    }
    
    if (month == 9) {
        answer = ((day + 14) - 5)%7 + doomsday;
    }
    
    if (month == 7) {
        answer = ((day + 14) - 11)%7 + doomsday;
    }
    
    if (answer > 6) {
        answer = answer - 7;
    }
    
    
    
    return (answer);
}