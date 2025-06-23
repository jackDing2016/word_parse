#include <stdio.h>
#include <stdlib.h>

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

//	char *wordarr =  calloc( 10, 50 );
	char *word = calloc( 50, sizeof(char) );
	
	int wordindex = 0;
	while( (cc = *contents) != '\0' ) {
//		wordarr[ wordarrindex ] = cc;
//		wordarr[ wordarrindex ]++;
		*( word + wordindex ) = cc;
		wordindex++;
		if ( cc == ' ' ) {
//			wordarrindex++;
			printf( "word is %s\n", word );
			wordindex = 0;
			
		}
		printf( "%c\n", cc );
		contents++;
	}	

	
/*	
	for( int i = 0; i < 10; i++ ) {
		printf( "%c\n", wordarr[i] );
	} 
*/	
	// insert new word	
//	char *aword = "time";

//	fseek( fp, SEEK_CUR, SEEK_END );
	char *aword = argv[1];	

	char c;
	while( c = *aword  ) {
		putc( c, fp );
		aword++;
	}
	putc( ' ', fp );		

}


