//
//  main.c
//  Sort3
//
//  Created by Jacinto Guevarra Churches on 24/03/2014.
//  Copyright (c) 2014 Jacinto Guevarra Churches. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>


int main(int argc, char * argv[]) {
    
    int first, second, third;
    
    scanf ("%d %d %d", &first, &second, &third);
    // 1
    if(first >= second && second >= third) {
        printf("%d\n%d\n%d\n", third, second, first);
    } else {
        // 2
        if(first >= third && third >= second) {
            printf("%d\n%d\n%d\n", second, third, first);
        } else {
            // 3
            if(second >= first && first >= third) {
                printf("%d\n%d\n%d\n", third, first, second);
            } else {
                // 4
                if(second >= third && third >= first) {
                    printf("%d\n%d\n%d\n", first, third, second);
                } else {
                    // 5
                    if(third >= second && second >= first) {
                        printf("%d\n%d\n%d\n", first, second, third);
                    } else {
                        // 6
                        if(third >= first && first >= second) {
                            printf("%d\n%d\n%d\n", second, first, third);
                    }
                    }
                }
            }
        }
    }


    return EXIT_SUCCESS;
}

