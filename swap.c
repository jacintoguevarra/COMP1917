//swap.c
//Jacinto Guevarra Churches
//12/5/14
//better late than never

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

void swap(int *a,int *b);

int main (int argc, char * argv[]){

	int a = 2;
	int b = 5;

	printf ("before swap %d %d\n", a, b);
	swap (&a, &b); 
	printf ("after swap %d %d\n", a, b);

	return EXIT_SUCCESS;
}

void swap(int *a, int *b)  {


	int temp =*a;
	*a = *b;
	*b = temp;
	printf ("swap %d %d\n", *a, *b);

	return;
}