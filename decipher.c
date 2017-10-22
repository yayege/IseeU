#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

void decrypt(char *c,int key);   //function prototype 
int main(int argc, const char * argv[]) {
    char c;
   //error check 
    if (argv[1]==NULL){
        
        printf("Please present a file\n");
     }
     else if(argv[2]==NULL){
        
        printf("Please present a key\n");
    }
    
    
    FILE *file;     //file pointer 
    file=fopen(argv[1],"r+");    //openiing the file 
    if (file){
        while((c=getc(file))!=EOF){    //get characters until the end of file 
                decrypt(&c,atoi(argv[2]));    //function call atoi for reference to int
                fseek(file,ftell(file)-1,SEEK_SET); //changing the position for replace 
                fprintf(file,"%c",c);    //print the new value to file 
        }
        printf("\n");
            
    }else{
        printf("Error!Check your filename and path!\n");
    }
    
    
    return 0;
}

void decrypt (char *c,int key){
    char i=*c;    //pointer to char
   
    int pos=i; //char to int ascii 
    int newPos;
    
    if(pos==32) newPos=pos;
    if( pos>64 && pos<91 ){
       newPos=pos+key;
       if(newPos>90) newPos=64+(newPos-90);
    }
    else if(pos>96 && pos<123){
       newPos=pos+key;
       if(newPos>122) newPos=96+(newPos-122);
    } 
    else {
         newPos=pos;   
}
    *c=newPos;  //changing the value 
}
