// Simple performance test of C hash table set

// See perftest.sh for results

#include "../lib/ht.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <string.h>

void exit_nomem(void) {
    fprintf(stderr, "out of memory\n");
    exit(1);
}

void* found;

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "usage: perftest file\n");
        return 1;
    }

    // Read entire file into memory.
    FILE* f = fopen(argv[1], "rb");
    if (f == NULL) {
        fprintf(stderr, "can't open file: %s\n", argv[1]);
        return 1;
    }
    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    fseek(f, 0, SEEK_SET);
    char* contents = (char*)malloc(size + 1);
    if (contents == NULL) {
        exit_nomem();
    }
    size_t nread = fread(contents, 1, size, f);
    if ((long)nread != size) {
        fprintf(stderr, "read %ld bytes instead of %ld", (long)nread, size);
        return 1;
    }
    fclose(f);
    contents[size] = 0;

    ht* counts = ht_create();
    if (counts == NULL) {
        exit_nomem();
    }

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
/*
	while (*word){
		printf("word is %c\n", word);
		//*word = tolower(*word);
		word++;
	}	
*/

        // Look up word.
        void* value = ht_get(counts, word);
        if (value != NULL) {
            // Already exists, increment int that value points to.
            int* pcount = (int*)value;
            (*pcount)++;
            continue;
        }

        // Word not found, allocate space for new int and set to 1.
        int* pcount = malloc(sizeof(int));
        if (pcount == NULL) {
            exit_nomem();
        }
        *pcount = 1;
        if (ht_set(counts, word, pcount) == NULL) {
            exit_nomem();
        }
    }
    
    hti it = ht_iterator(counts);
		
    char *minnum = argv[2];
    char *maxnum = argv[3];

   
   	
    printf( "min num is %s\n ", minnum );
	
    while (ht_next(&it)) {
	    int numa = *(int*)it.value;
	    if(numa < atoi( maxnum ) && numa > atoi( minnum ) )
 //	  if(numa < 20 && numa > 10)
		printf( "%s %d\n", it.key, numa );
    }


    

    // Copy keys to array
    /*
    const char** keys = malloc(ht_length(counts) * sizeof(char*));
    if (keys == NULL) {
        exit_nomem();
    }
    hti it = ht_iterator(counts);
    int i = 0;
    while (ht_next(&it)) {
        keys[i] = it.key;
        i++;
    }

    ht* table = ht_create();
    if (table == NULL) {
        exit_nomem();
    }

    int value = 1; // dummy value
    clock_t start = clock();
    for (int i=0; i<ht_length(counts); i++) {
        if (ht_set(table, keys[i], &value) == NULL) {
            exit_nomem();
        }
    }
    clock_t end = clock();
    double elapsed_ms = (double)(end - start) / CLOCKS_PER_SEC * 1000;
    printf("setting %lu keys: %.09fms\n", ht_length(counts), elapsed_ms);

    */
    return 0;
}
