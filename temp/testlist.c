#include <stdio.h>
#include <stdlib.h>
#include "testlist.h"

struct arraylist {
	char *data[100];
	int *nextpositiontoadd;
}; 

struct arraylist *createarraylist() {
		
	struct arraylist *al = malloc( sizeof( struct arraylist ) );

	for( int i = 0; i < 10; i++ ) {
		al -> data[ i ] = calloc( 50, sizeof( char ) );
	}
	
	al -> nextpositiontoadd = malloc( sizeof( int ) );
	*( al -> nextpositiontoadd ) = 0;

	return al;	
}

void addelement( struct arraylist *arraylist, char *value ) {
	char c;	
	int indexinside = 0;
	while( ( c = *value ) != '\0' ) {
		*( arraylist -> data[ *(arraylist -> nextpositiontoadd) ] + indexinside ) = c;
		value++;
		indexinside++;
	}
	*( arraylist -> nextpositiontoadd ) = *( arraylist -> nextpositiontoadd ) + 1;	
}

void iteratearraylist( struct arraylist *arraylist ) {
	for( int i = 0; i < 10; i++ ) {
		printf( "word is %s\n", arraylist -> data[ i ] );
	}
}


int *size( struct arraylist *arraylist ){
	return arraylist -> nextpositiontoadd;		
}


