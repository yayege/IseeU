#include <stdio.h>
#include <math.h> 
#include <string.h> 

int main(){ 
	int sum1; 
	int sum2; 

	sum1=0; sum2=0; 

	int temp=0; 
	for(int i=0; i<=100; i++){
		temp=temp+pow(i,2);
	}
	sum1=temp; 

	for(int j=0; j<=100; j++){
		sum2=sum2+j; 

	}
	sum2=pow(sum2,2);

	int diff; 
	diff=sum2-sum1; 

	printf("\n");

	printf("The difference is %d\n\n", diff);



}
