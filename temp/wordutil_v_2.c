
#include "wordutil_v_2.h"

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../lib/stringutil.h"
/* #include "../lib/datastructs-c/arraylist.h" */
arraylist *readwordsfromfile(FILE *f) {
    // Read entire file into memory.
    //    FILE* f = fopen(argv[1], "rb");
    if (f == NULL) {
	fprintf(stderr, "can't open file\n");
    }

    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    fseek(f, 0, SEEK_SET);
    char *contents = (char *)malloc(size + 1);
    if (contents == NULL) {
    }
    size_t nread = fread(contents, 1, size, f);
    if ((long)nread != size) {
	fprintf(stderr, "read %ld bytes instead of %ld", (long)nread, size);
    }
    fclose(f);
    contents[size] = 0;
    printf("higuy2\n");

    // create an arraylist to store words
    arraylist *al = arraylist_create();
    for (char *p = contents; *p;) {
	// Skip whitespace.
	while (*p && *p <= ' ') {
	    p++;
	}
	char *word = p;

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
	if (iscontainelement(al, word) == false) {
	    arraylist_add(al, word);
	}
    }
    // iterate al
    /* iteratearraylist( al ); */
    return al;
}
void getdictionaryform(char *word) {
    int len = strlen(word);
    /* ed past tense form of a verb */
    /* s plural form of a noun */
    /* ly an adverb which derived from an adjective */
    char lastalphabet = word[len - 1];
    char lastsecondalphabet = word[len - 2];

    if (lastalphabet == 'd') {
	if (lastsecondalphabet == 'e') {
	    // cut it
	    word[len - 1] = '\0';
	    word[len - 2] = '\0';
	}
    } else if (lastalphabet == 'y') {
	if (lastsecondalphabet == 'l') {
	    // cut it
	    word[len - 1] = '\0';
	    word[len - 2] = '\0';
	}
    } else if (lastalphabet == 's') {
	if (lastsecondalphabet == 'e') {
	    // cut it
	}
    }

    /* gerund which is end with ing */

    if (len >= 5) {
	char *gerund_suffix = "ing";
	char *p;
	p = word;
	p = p + len - 3;
	bool res = isequal(gerund_suffix, p);
	if (res == true) {
	    // cut it
	    word[len - 1] = '\0';
	    word[len - 2] = '\0';
	    word[len - 3] = '\0';
	}
    }
}
