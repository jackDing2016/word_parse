#include <stdio.h>
#include <stdlib.h>
int main(){
	char *wordarr[ 10 ];
	
	// do some initial behavior for wordarr
	for( int i = 0; i < 10; i++ ) {
		wordarr[ i ] = calloc( 50, sizeof( char ) );
	}
	
	// assign some word to wordarr
	char *worda = "fish";
	char *wordb = "flying";
	char c;
	int index = 0;
	while ( ( c = *worda ) != '\0' ) {
		*( wordarr[ 0 ] + index	) = c;
		index++;
		worda++;
	}
	index = 0;
	while ( ( c = *wordb ) != '\0' ) {
		*( wordarr[ 1 ] + index	) = c;
		index++;
		wordb++;
	}

	printf( "word a is %s\n", wordarr[ 0 ] );
	printf( "word b is %s\n", wordarr[ 1 ] );

}
