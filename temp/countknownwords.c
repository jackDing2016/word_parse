
#include <stdio.h>
#include <stdlib.h>

int main() {
	
	int allknownwords =  0 ;
	
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

	while( (cc = *contents) != '\0' ) {
		*( word + wordindex ) = cc;
		wordindex++;
		if ( cc == ' ' ) {
			//  word count + 1
			allknownwords++;
			wordindex = 0;
			
		}
		contents++;
	}

	printf( "The number of the words you have knows is %d\n", allknownwords );
}
