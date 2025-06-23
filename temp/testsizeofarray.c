#include <stdio.h>
#include <stdlib.h>

void initialarray( char *arr[]);
void addvaluetoarray( char *arr[], char *value, int currentsize );
void iteratearray( char *arr[] );
int main(){
	char *stringarr[ 100 ];
	// number of elements in array
	int sizeofarray = 0;
	initialarray( stringarr );
	// add a value to array
	addvaluetoarray( stringarr, "office", 0 );
	// iterate array
	iteratearray( stringarr );		
}

void initialarray( char *arr[] ){
	for( int i = 0; i < 10; i++ ) {
		arr[ i ] = calloc( 50, sizeof( char ) );
	}
}


void addvaluetoarray( char *arr[], char *value, int currentsize ){
	char c;	
	int indexinside = 0;
	while( ( c = *value ) != '\0' ) {
		*(arr[ currentsize ] + indexinside ) = c;
		value++;
		indexinside++;
	}	
}

void iteratearray( char *arr[] ){
	for( int i = 0; i < 10; i++ ) {
		printf( "word is %s\n", arr[ i ] );
	}
}

