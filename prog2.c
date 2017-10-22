#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000
//DEFINING THE MAXIMUM LENGTH 
//COPY METHOD 
char *copy( char *s, char *t, int n)
{
	int i = 1;
	while ( ( (*s = *t) != '\0' ) && i <= n-1 )
	{
		s++;
		t++;
		i++;
	}
	s++;
	*s = '\0';
	
	return s;
}
//STRNCAT 
char * cat( char *s, char *t, int n )
{
	int i = 1;
	while ( *s != '\0' ){
		s++;
	}
	while ( ((*s++ = *t++) != '\0') && i++ <= n-1 )
		;
	*s++ = '\0';

	return s;
}
//COMPARE
int compare( char *s, char *t, int n )			
{
	char scopy[strlen(s)], tcopy[strlen(t)];	
	char *pscopy, *ptcopy;
	pscopy = &scopy[0];
	ptcopy = &tcopy[0];
	copy( pscopy, s, strlen(s) );
	copy( ptcopy, t, strlen(t) );

	for ( int i = 1; *s==*t && i<=n-1; s++, t++, i++ )
	{								
		if (*s == '\0' ) {   
			printf( "\"%s\" = \"%s\"", pscopy, ptcopy );
			return 0;
		}
	}								
	if ( *s < *t ){
		printf( "\"%s\" < \"%s\"", pscopy, ptcopy );
		return -1;
	}
	else if ( *s > *t ){
		printf( "\"%s\" > \"%s\"", pscopy, ptcopy );
		return 1;
	}
	else{
		printf( "\"%s\" = \"%s\"", pscopy, ptcopy );
		return 0;
	}
}

void main()
{
 //COPYING THE ELEMENTS AND ARRAYS
	char str1[MAX_LEN], str2[MAX_LEN];		
	char *Pstr1 = &str1[0];					
	char *Pstr2 = &str2[0];
	int n;
	char copy1[MAX_LEN], copy2[MAX_LEN];			
	char *Pcopy1 = &copy1[0];
	char *Pcopy2 = &copy2[0];

	printf("\nEnter the first string: ");
	gets( str1 );
	printf( "\n" ); 


	printf( "Enter the second string: ");
				
	gets( str2 );
	printf ( "\n" );
	printf( "Enter the number: " );
	scanf( "%i", &n );
	printf( "\n" );
//FUNCTION CALLS
	copy( Pcopy1, Pstr1, MAX_LEN );
	copy( Pcopy2, Pstr2, MAX_LEN );
	copy( Pcopy1, Pcopy2, n );
	printf( "strncpy is \"%s\" \n\n", copy1 );
	
	copy( Pcopy1, Pstr1, MAX_LEN );
	copy( Pcopy2, Pstr2, MAX_LEN );
	cat( Pcopy1, Pcopy2, n );
	printf( "strncat is \"%s\" \n\n", copy1 );

	copy( Pcopy1, Pstr1, MAX_LEN );
        copy( Pcopy2, Pstr2, MAX_LEN );
        printf( "strncmp is ");
	compare( Pcopy1, Pcopy2, n );
	printf( "\n\n" );
}
