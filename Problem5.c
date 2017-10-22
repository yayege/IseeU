#include <stdio.h> 
#include <stdlib.h>
#include <math.h>

int main(){ 
	
	for( int z=2000; z<100000; z++){
	
		int count=0; 
		for(int i=0; i<=20; i++) {
		 	if(z%i==0){ 
   			count++;  
		 	}
		 	else{ 
				continue; 
		 	}
	    }
			if(count==20){
				int number; 
				number=z; 
				printf("%d",number);
				break;
			}
			else{
				count=0;
        	} 

    } 		
}






