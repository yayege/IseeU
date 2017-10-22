#include <stdio.h>
#include <math.h>


int main(){

	int number; 

	printf("What is the number ? \n");
	scanf("%d", &number);


	printf("The Prime factors are: ");
	
	for(int i=0; i<number ;i++){

		if( number % i==0  &&  ifPrime(i) ){
			printf("%d",i);

		}
	}
}
int ifPrime(int x){

	for (int i=1; i<x; i++){
		if(x % i == 0 ){
			return 0; 
		}
		else{
			return 1; 
		}
	}
}