#include "indexservice.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "wordindex.h"
/* #include "/home/jack/develop/c/lib/datastructs-c/arraylist.h" */
#include "/home/jack/develop/c/lib/stringutil.h"

arraylist *buildindex() {
    FILE *file =
	fopen("/home/jack/develop/c/word_parse/data/dict/longmandict.txt", "r");
    char *ending_word = "<end>";

    char *word = calloc(100, sizeof(char));
    char *wordtoindex = calloc(100, sizeof(char));
    char *pword = word;
    char a;
    int currentindex = 0;
    arraylist *wordindexlist = arraylist_create();
    while ((a = fgetc(file)) != EOF) {
	if (a == ' ' || a == '\n' || a == '\r' || a == '\t') {
	    *pword = '\0';
	    pword = word;
	    char startsignal = *word;
	    int startindex;
	    if (startsignal == '<') {
		if (!isequal(ending_word, word)) {
		    startindex = currentindex;
		    strcpy(wordtoindex, word);
		} else {
		    int endindex = currentindex;
		    struct wordindex *w =
			newwordindex(wordtoindex, startindex, endindex);
		    arraylist_add(wordindexlist, w);
		}
	    }
	} else {
	    *pword = a;
	    pword++;
	}
	currentindex++;
    }
    return wordindexlist;
}

void saveindex(arraylist *indexlist) {
    FILE *f = fopen("jackding.txt", "wb");
    int size = arraylist_size(indexlist);
    for (int i = 0; i < size; i++) {
	struct wordindex *w = arraylist_get(indexlist, i);
	writewordindex(w, f);
    }
}

arraylist *loadindex() {
    FILE *f = fopen("/home/jack/develop/c/word_parse/src/jackding.txt", "rb");
    arraylist *l = arraylist_create();
    /* for (int i = 0; i < 20; i++) { */
    /* struct wordindex *w = readwordindex(f); */
    /* arraylist_add(l, w); */
    /* } */
    while (!feof(f)) {
	/* while (true) { */
	struct wordindex *w = readwordindex(f);
	arraylist_add(l, w);
    }
    return l;
}

hashtable *loadindextable() {
    FILE *f = fopen("/home/jack/develop/c/word_parse/src/jackding.txt", "rb");
    hashtable *t = hashtable_create();
    while (!feof(f)) {
	struct wordindex *w = readwordindex(f);
	/* hashtable_set(t, w->name->value, &(w->startindex)); */
	hashtable_set(t, w->name->value, w);
    }
    return t;
}
bool justtest() {
    char *a = malloc(sizeof(char));
    return true;
}
