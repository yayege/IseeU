#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

void encrypt(char *c,int key);  //function prototype
int main(int argc, const char * argv[]) {
    char c;
    
     if (argv[1]==NULL){   //file name doesnt exist 
        
        printf("Place input a valid file name\n");
     }
     else if(argv[2]==NULL){ //key doesnt exist
        
        printf("Key must be a number and cannot be empty!\n");
    }
    
    
    FILE *file;     //file pointer decleration 
    file=fopen(argv[1],"r+");     //opening the file 
    if (file){
        while((c=getc(file))!=EOF){      //get char untill the end of file 
                encrypt(&c,atoi(argv[2]));     //function call 
                fseek(file,ftell(file)-1,SEEK_SET);  //change the position 
                fprintf(file,"%c",c);   //replace it with a new char 
        }
        printf("\n");
            
    }else{
        printf("File dose not exsit! Check your filename and path!\n");
    }
    
    
    return 0;
}

void encrypt (char *c,int key){
    char i=*c;    //pointer to char 
   
    int pos=i;   //char to int (ascii) 
    int newPos;
    
    if(pos==32) newPos=pos;
    if( pos>64 && pos<91 ){
       newPos=pos-key;
       if(newPos<65) newPos=91-(65-newPos);  //out of border 
    }
    else if( pos>96 && pos<123 ){
       newPos=pos-key;
       if(newPos<97) newPos=123-(97-newPos);  //if out of border 
    } 
    else {
         newPos=pos;   //if it is not letters do nott change it
    }

    *c=newPos;  //integer to pointer, chanhging the value 
}
