

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../lib/datastructs-c/hashtable.h"

char *popword( int s, int e, char *source );


int main(){

	hashtable *t = hashtable_create();

	char *sentence = "we have a lot of task to do";

	char *currentp;

	char *wordsource[ 100 ];

	char ch;

	int startIndex = 0;
	int endIndex = 0;

	currentp = sentence;

	int currentIndex = 0;




	while ( ( ch = *(currentp++ ) ) != '\0' ) {
		if ( ch == ' ' ) {

			char *aword = popword( startIndex, endIndex, sentence );

			printf("a word is %s\n", aword);

			startIndex = endIndex + 1;

			hashtable_set( t, aword, "2" );

			
		}
		endIndex++;
	}

	char *value = hashtable_get( t, "lot" );
	printf( "value is %s\n", value );

}


char *popword( int s, int e, char *source ) {
	
	int strlen = e - s + 1;
	char *res = ( char * ) malloc( strlen ) ;
//	char *res = "a";
	for( int i = s; i < e; i++ ) {
	//	printf("%c", source[ i ]);
		res[ i - s ] = source[ i ];
	}
	return res;

}



