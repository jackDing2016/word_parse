#include <stdio.h>
#include <stdlib.h>
#include "testlist.h"

struct arraylist {
	char *data[100];
	int *nextpositiontoadd;
	int *availablesize;
}; 


struct arraylist *createarraylist() {
		
	struct arraylist *al = malloc( sizeof( struct arraylist ) );

	for( int i = 0; i < 10; i++ ) {
		al -> data[ i ] = calloc( 50, sizeof( char ) );
	}
	al -> availablesize = malloc( sizeof( int ) );
	*( al -> availablesize ) = 10;
	
	al -> nextpositiontoadd = malloc( sizeof( int ) );
	*( al -> nextpositiontoadd ) = 0;

	return al;	
}

void addelement( struct arraylist *arraylist, char *value ) {

	char c;	
	int indexinside = 0;

	printf( "availablesize is %d\n", *( arraylist -> availablesize ) );

	// perform capcity extension
	if ( *( arraylist -> availablesize ) < 1 ) {
		for( int i = 0; i < 10; i++ ) {
			arraylist -> data[ i + *(arraylist -> nextpositiontoadd ) ] = calloc( 50, sizeof( char ) );
		}
		*( arraylist -> availablesize ) = 10;
	}
	while( ( c = *value ) != '\0' ) {
		*(arraylist -> data[ *( arraylist -> nextpositiontoadd) ] + indexinside ) = c;
		value++;
		indexinside++;
	}
	*( arraylist -> nextpositiontoadd ) = *( arraylist -> nextpositiontoadd ) + 1;		
	printf( "elements added successfully\n" );
	*( arraylist -> availablesize  ) = *( arraylist -> availablesize  ) - 1; 	

}

void iteratearraylist( struct arraylist *arraylist ) {
	int length = *( arraylist -> nextpositiontoadd );
	for( int i = 0; i < length; i++ ) {
		printf( "word is %s\n", arraylist -> data[ i ] );
	}
}


int *size( struct arraylist *arraylist ){
	return arraylist -> nextpositiontoadd;		
}


