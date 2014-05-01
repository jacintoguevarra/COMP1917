//danish.c
//prints danish flag
//Jacinto Guevarra Churches
//12/5/14
//better late than never

#include <stdio.h>
#include <stdlib.h>

void showDanish(void);

int main(int argc, char * argv[]){
    
	showDanish();
    
	return EXIT_SUCCESS;
}

void showDanish(void){
    
	int count;
    
	count = 0;
    
	while (count < 5){
        
		while (count == 2){
            
			printf("\n");
            
            count ++;
		}
        
		printf("** *********\n");
        
        count++;
	}
    
	return;
}