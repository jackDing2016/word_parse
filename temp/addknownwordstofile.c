#include <stdio.h>
#include <stdlib.h>

#include "testlist.h"

int main( int argc, char *argv[] ){
	
	// load all words in file to memory	
	FILE *fp = fopen( "/home/jack/test.txt", "r+" );
	
	fseek( fp, 0, SEEK_END );
	long size = ftell( fp );
	
	// can not understand  
	fseek( fp, 0, SEEK_SET );

	char *contents = ( char* )malloc( size + 1 );

	size_t nread = fread( contents, 1, size, fp );

	char cc;

	char *word = calloc( 50, sizeof(char) );
	int wordindex = 0;

	// create array list
	struct arraylist *al = createarraylist();
	
//	while( (cc = *contents) != '\0' ) {
		*( word + wordindex ) = cc;
		wordindex++;
		if ( cc == '\n' ) {
			// add word
			addelement( al, word );
			wordindex = 0;
			
		}

		contents++;
//	}	

	// iterate list , just for test
//	iteratearraylist( al );
	
/*	
	for( int i = 0; i < 10; i++ ) {
		printf( "%c\n", wordarr[i] );
	} 
*/	
	// insert new word	
//	char *aword = "time";

//	fseek( fp, SEEK_CUR, SEEK_END );
	char *aword = argv[1];	

	// if not contain the word , add it	
	if( iscontainelement( al, aword ) == false ) {
		char c;
		while( c = *aword  ) {
			putc( c, fp );
			aword++;
		}
		putc( '\n', fp );		
		printf( "you have added the word to file successfully.\n" );

	}
	else {
		printf( "you have added the word.\n" );
	}
}


