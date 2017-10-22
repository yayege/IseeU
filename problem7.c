#include <stdio.h>
#include <math.h>

int isPrime(int num){ 
	
	int count1=0; 
	for(int i=2; i<num; i++){
		if(num%i==0){
			count1++;  
		}
		else{ 
			continue;  
		}
	}
	
	//count check
	if(count1==0){
		return 1; 
	}
	else{ 
		return 0; 
	}
}

int main(){ 
	
	int count2=0; 

	int primeArray[10001];

	for(int i=1; i<1000000; i++){
		if(isPrime(i)){
			primeArray[count2]=i;
			count2++; 
		}
		else{
			continue; 
		}
	}

	printf("\n\n 10,001 th prime is %d \n\n", primeArray[10000]); 
}

