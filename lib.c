#include<stdio.h>
int fib(int x){
   if(x==0) return 0; 
    
   if(x==1) return 1;
   
   return fib(x-1)+fib(x-2); 

} 

void sort(int *p, int size){
   int *i, *j, temp; 
   for(i=p; i<p+size;i++){
      for(j=i+1; j<p+size; j++){
             if(*j < *i) {
                temp=*j;
                *j=*i;
                *i=temp; 
              }

          }  
      } 
}
