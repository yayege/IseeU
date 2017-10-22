#include <stdio.h>
#include <stdlib.h>

//FIBONACCI FUNCTION 
 int fibonacci(int x){
    int f[x+1];
    f[1]=f[2]=1;
    for(int i=3; i<=x; i++){
         f[i]=f[i-1] + f[i-2];
  } 
    return f[x];
}

int main( int argc, char *argv[] )  {
    int size=0; 
    int *n=malloc( size * sizeof(int) );
//MALLOC FOR THE SIZE
// FILE OPEN 
    FILE *f;
    f=fopen( argv[1] , "r+");
    //ERROR CHECK 
         if(argv[1]==NULL) printf("Please present a input file.\n");

         if (f==NULL){
    
             printf("Error reading file.\n");
         } 
   //SUM OF THE NUMBERS  

   int num, sum=0; 
   
    while( fscanf(f,"%d",&num) ==1 ){
    
             sum=sum+num; 
      }  

     printf("\n The sum of the number is %d \n ",sum);
     rewind(f);
  //fIBONACCI PART 


    printf("The fibonacci Sequence of each number is : \n");
   
     
    while( fscanf(f,"%d",&num)==1 ){
          int fib=fibonacci(num);
          printf("Fib(%i) is %i\n",num, fib);
}
     printf("\n");
     fclose(f);
}
