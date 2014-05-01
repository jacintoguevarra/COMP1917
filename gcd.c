//gcd


#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b);


int main (int argc, char * argv[]){

	int a, b;

	printf ("Please enter two integers\n");

	scanf("%d %d", &a, &b);
	
	int gcd (int a, int b);

	printf("%d\n", gcd(a, b));

	return EXIT_SUCCESS;
}

int gcd (int a, int b){

	int divisor = 1;

	int answer;

	int number;

	if(a > b){

		number = a;

	} else {

		number = b;
	}

	while(divisor < number){

		if(a % divisor == 0 && b % divisor == 0){

			answer = divisor;
		} 

		divisor++;

	}

	return answer;
}