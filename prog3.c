#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include "lib.h"
#include <time.h>

//FIRST CHILD PROCESS
void child1( int x ) 		
{
	printf( "   Sort process started\n\n");
	int number[x];

	time_t t;
	srand((unsigned) time(&t));			
	
	for ( int i = 0; i<x; i++)
	{
		number[i] = rand() % 100;		
	}
	printf( "   Random numbers generated:\n" );
	int n;
	for ( int i = 0; i<x; i++ )
	{
		n = number[i];
		printf( " %4d", n );
	}
	
	printf( "\n\n   Sorted sequence:\n" );
	sort( number, x );
	for ( int i = 0; i<x; i++ )
        {
                n = number[i];
                printf( " %4d", n );
        }

	printf( "\n\n   Sort process exits\n\n" );
	
}
//SECOND CHILD PROCESS
void child2( int y )
{
	printf( "      Fibonacci process started\n\n" );
	printf( "      Input number: %i\n\n", y );
	long fiby = fib(y);
	printf( "      Fibonacci number f(%d) is %1ld\n\n", y, fiby );
	printf( "      Fibonacci process exits.\n\n");
}
//MAIN FUNCTION STARTS HERE
void main( int argc, char *argv[] )
{
	//ATOI 
        int x = atoi(argv[1]);
        int y = atoi(argv[2]);
        //FORK 
        int pid = fork ();
  	if (pid > 0)
  	{
    	
		printf( "Main process started\n\n");
                printf( "Number of random number = %i\n\n", x );
                printf( "Fibonacci input         = %i\n\n", y );
		
	        pid = wait();
                printf( "Main process waits\n\n" );
		printf( "Main process exits\n\n" );
  	}
  	else if (pid == 0)
  	{

    		printf( "Sort process created\n\n" );
                child1(x);
	
		if (pid == 0)
		{

			printf( "Fibonacci process created\n\n" );
                        child2(y);
		}
  	}
  	else if (pid < 0)
  	{
    		perror ("Unable to fork()\n");
    		exit (1);
  	}
}
