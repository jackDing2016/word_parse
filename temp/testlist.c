#include <stdio.h>
#include <stdlib.h>
#include "testlist.h"
#include <stdbool.h>
#include "../lib/stringutil.h"
//void setavailablesize( int *pavailablesize );

struct arraylist {
	char *data[100];
	int *nextpositiontoadd;
//	int *availablesize;
	int availablesize;
};


struct arraylist *createarraylist() {
		
	struct arraylist *al = malloc( sizeof( struct arraylist ) );

	for( int i = 0; i < 10; i++ ) {
		al -> data[ i ] = calloc( 50, sizeof( char ) );
	}

//	al -> availablesize = malloc( sizeof( int ) );
//	*( al -> availablesize ) = 10;
	al -> availablesize = 10;
	
	al -> nextpositiontoadd = malloc( sizeof( int ) );
	*( al -> nextpositiontoadd ) = 0;

	return al;	
}

void addelement( struct arraylist *arraylist, char *value ) {
	
	int as = arraylist -> availablesize;	

	char c;	
	int indexinside = 0;

//	printf( "availablesize is %d\n", as );

	// perform capcity extension
	if ( as  < 1 ) {
		for( int i = 0; i < 10; i++ ) {
			arraylist -> data[ i + *(arraylist -> nextpositiontoadd ) ] = calloc( 50, sizeof( char ) );
		}
		*(&as) = 10;
	}
	while( ( c = *value ) != '\0' ) {
		*(arraylist -> data[ *( arraylist -> nextpositiontoadd) ] + indexinside ) = c;
		value++;
		indexinside++;
	}
	*( arraylist -> nextpositiontoadd ) = *( arraylist -> nextpositiontoadd ) + 1;		
//	printf( "elements added successfully\n" );
//	*( arraylist -> availablesize  ) = *( arraylist -> availablesize  ) - 1; 	
//	*(&as) = as - 1;
	*( &( arraylist -> availablesize) ) = as - 1;
}

void iteratearraylist( struct arraylist *arraylist ) {
	int length = *( arraylist -> nextpositiontoadd );
	for( int i = 0; i < length; i++ ) {
		printf( "word is %s\n", arraylist -> data[ i ] );
	}
}

int size( struct arraylist *arraylist ){
	return *( arraylist -> nextpositiontoadd );		
}


bool iscontainelement( struct arraylist *al, char *val ) {
	int length = *( al -> nextpositiontoadd );
	bool result = false;
	for( int i = 0; i < length; i++ ) {
		char *element = al -> data[ i ];
		result = isequal( val, element );
		if ( result == true ) {
			return result;
		}		
//		printf( "word is %s\n", arraylist -> data[ i ] );
	}
	return result; 
}


char *getelement( struct arraylist *al, int index ) {
	return al -> data[ index ];	
}

