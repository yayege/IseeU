#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int isPalindromic(int);
int countDigits(int);

int main(int argc, char const *argv[])
{
	
	int biggestnum; 
	int tempb;

	for( int i=900; i<1000; i++){
		for(int j=900; j<1000 ; j++){
			if(isPalindromic(i*j)){
				tempb=i*j; 
				if (tempb>biggestnum) biggestnum=tempb;
			}
			else{
				continue;
			}
		}
	}

	printf("%d\n",biggestnum);
	
	return 0;
}

int isPalindromic(int num){
	int num1[6]; 
	num1[0]=num % 10;
    int temp; 

	for( int i=1; i<6; i++){
		temp=num/10;
		num1[i]=temp % 10;
		num=temp;	
	}
	
	int count=0; 
	for(int j=0, u=5; j<3, u>=3; j++, u--){
		if(num1[j] != num1[u]){
           count++;
		}
		else{
		   continue;
		}
	}
	
	if(count==0){
		return 1;
	}
	else{
		return 0; 
	}
}
