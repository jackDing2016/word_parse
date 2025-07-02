#include <stdio.h>
#include "wordutil.h"
#include "testlist.h"
int main() {
    /* FILE* f = fopen( "/home/jack/develop/c/wordparse/test/testdata-mini.txt" , "rb"); */
    FILE *f = fopen( "/home/jack/develop/c/wordparse/data/english/knownwords.txt_back", "rb" );
    struct arraylist *al = readwordsfromfile( f );	
    int size = getsize( al );
    for ( int i = 0; i < size; i++ ) {    	
	char *word = getelement( al, i );
	printf( "a word in array list is %s\n", word );
    }
}
