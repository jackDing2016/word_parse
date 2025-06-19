#include <stdio.h>
#include <ctype.h>

#include <stdlib.h>

int main(){

//	char a[10] = "INTEREST";

	char *b = "INTEREST";
//	a[0] = tolower(a[0]);
//	a[0] = 'a';
	
//	printf( "%s\n", a );
//	printf( "%c\n", a[0] );
	char *a;
//	a = malloc(sizeof(char));
//	a = calloc(10, sizeof(char));
	a = (char*)calloc(10, sizeof(char));

//	a[0] = 'a';
	char t;
	int i = 0;
	while ( ( t = *b++ ) != '\0' ) {
		printf( "%c\n", t );
//		*a = tolower( t ); 
		*(a + i ) = tolower( t );
		printf( "%c\n", *a );
		i++;

	}
	char f;
	while ( ( f = *a++ ) != '\0' ) {
		printf( "%c", f );
	}
	printf( "\n" );

//	printf( "%s\n", a );
}
