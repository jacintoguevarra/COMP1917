//wondrous.c
//Jacinto Guevarra Churches
//12/5/14
//better late than never

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int printWondrous (int start);

int start;

int main (int argc, char * argv[]){

	printWondrous (start);

	return EXIT_SUCCESS;
}


int printWondrous (int start){

	scanf("%d", &start);

	assert (start >0);

	int number;

	number = 0;

	int counter = start;
 
 	int count = 0;

	if(start == 1){
		printf("%d", start);

		count = count + 1;

		} else if (start == 2){
			printf("%d ", start);

			count = count + 1;

			}

    while (counter > 1){

    if ((counter%2) == 0){
    	number = (counter/2);
    		
    	printf("%d ", number);

    } else if((counter%2) != 0){
    	number = (counter*3+1);
    		
    	printf("%d ", number);
    	
    	    }

    	    
		counter = number;

		count++;

	}

	printf("\n%d\n", count);

	return count;
}
