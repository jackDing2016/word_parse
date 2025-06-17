#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main(){

	char *a = "abc";
//	printf( "%s\n", a );

	// you can just treat b as pointer
	char b[3] = "cba";

	//char *p = b[0];

	char *p = malloc( sizeof(char) );

	*p = b[0];	

//	printf( "%c\n", *p );
 //     	printf( "%c\n", *(++p) );
	//printf( "%c\n", *(b + 1) );
//	printf( "%c\n", b[1] );


//	printf( "%s\n", b );

	char *t = malloc( sizeof(char) );
	*t = 'T';
printf( "%c\n", *t );
printf( "%d\n", *t );

	char *smallt = malloc( sizeof(char) );
	*smallt =  tolower( *t );
printf( "%c\n", *smallt );
printf( "%d\n", *smallt );

//	int *j = 116;
	int *j = malloc( sizeof(int) );
	*j = 116;

printf( "%c\n", *j );



}
