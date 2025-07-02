
#include "testlist.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct arraylist *readwordsfromfile( FILE *f ) {
    // Read entire file into memory.
//    FILE* f = fopen(argv[1], "rb");
    if (f == NULL) {
	fprintf(stderr, "can't open file\n" );
    }
    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    fseek(f, 0, SEEK_SET);
    char* contents = (char*)malloc(size + 1);
    if (contents == NULL) {
    }
    size_t nread = fread(contents, 1, size, f);
    if ((long)nread != size) {
	fprintf(stderr, "read %ld bytes instead of %ld", (long)nread, size);
    }
    fclose(f);
    contents[size] = 0;


    // create an arraylist to store words
    struct arraylist *al = createarraylist();


    for (char* p = contents; *p;) {
	// Skip whitespace.
	while (*p && *p <= ' ') {
	    p++;
	}
	char* word = p;

	// Find end of word.
	while (*p && *p > ' ') {
	    p++;
	}
	if (*p != 0) {
	    *p = 0;
	    p++;
	}


	// remove non alpha in the word
	int j = 0;
	for (int i = 0; word[i] != '\0'; i++) {
	    if (isalpha(word[i])) {
		word[j++] = word[i];
	    }
	}
	word[j] = '\0';
	// convert word to lower case.
	for (int i = 0; i < strlen(word); i++) {
	    word[i] = tolower(word[i]);
	}
	// if not containt add the word
	if ( iscontainelement( al, word ) == false ){
	    addelement( al, word );
	}
    }
    // iterate al
    /* iteratearraylist( al ); */
    return al;
}
