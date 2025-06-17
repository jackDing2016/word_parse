
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../lib/ht.h"

char *popword( int s, int e, char *source );


int main(){

	ht *map = ht_create();

	char *sentence = "we have a lot of task to do a lot of have lot ";

	char *currentp;

	char ch;

	int startIndex = 0;
	int endIndex = 0;

	currentp = sentence;

	int currentIndex = 0;


	while ( ( ch = *(currentp++ ) ) != '\0' ) {
		if ( ch == ' ' ) {

			char *aword = popword( startIndex, endIndex, sentence );


			// look up word

			void *value = ht_get( map, aword );

			if ( value != NULL ) {
				int *pcount = ( int* )value;
				( *pcount )++;
			}
			else {
				int *pcount = malloc( sizeof(int) );
				*pcount = 1;
				ht_set( map, aword, pcount );
			}
			startIndex = endIndex + 1;
			
		}
		endIndex++;
	}

	hti it = ht_iterator(map);
    	while (ht_next(&it)) {
		printf("%s %d\n", it.key, *(int*)it.value);
        //	free(it.value);
    	}

	printf("%d\n", (int)ht_length(map));
}


char *popword( int s, int e, char *source ) {
	int strlen = e - s + 1;
	// need think for size of malloc
	char *res = ( char * ) malloc( strlen ) ;
	for( int i = s; i < e; i++ ) {
		res[ i - s ] = source[ i ];
	}
	return res;
}



