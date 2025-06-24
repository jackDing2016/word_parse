#include <stdio.h>

#include "testlist.h"

struct arraylist {
	char *data[100];
	int size;
}; 

struct arraylist *createarraylist() {
	
		

	for( int i = 0; i < 10; i++ ) {
		arr[ i ] = calloc( 50, sizeof( char ) );
	}
	printf( "create array list function \n" );	
}


/*

void addelement( char *arr[], char *value, int currentsize ) {
	char c;	
	int indexinside = 0;
	while( ( c = *value ) != '\0' ) {
		*(arr[ currentsize ] + indexinside ) = c;
		value++;
		indexinside++;
	}	
}

*/

/*

void iteratearraylist( char *arr[] ){
	for( int i = 0; i < 10; i++ ) {
		printf( "word is %s\n", arr[ i ] );
	}
}

*/

/*
void size(){
		
}

*/
