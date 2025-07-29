#include <stdio.h>

#include "wordutil_v_2.h"
#define KNOWNWORDSFILEPATH \
    "/home/jack/develop/c/word_parse/data/english/knownwords.txt"

int main() {
    FILE *fknownwords = fopen(KNOWNWORDSFILEPATH, "rb");
    struct arraylist *alknown = readwordsfromfile(fknownwords);
    FILE *fsource = fopen(
	"/home/jack/develop/c/word_parse/data/english/asubdata.txt", "rb");
    arraylist *alsource = readwordsfromfile(fsource);
    int sizesourceal = arraylist_size(alsource);
    arraylist *alunknown = arraylist_create();
    for (int i = 0; i < sizesourceal; i++) {
	char *element = arraylist_get(alsource, i);
	if (*element != '\0') {
	    // get the dictionary form of the word
	    getdictionaryform(element);
	    if (iscontainelement(alknown, element) == false) {
		arraylist_add(alunknown, element);
	    }
	}
    }
    /* iteratearraylist(alunknown); */

    for (int i = 0; i < alunknown->size; i++) {
	char *word = arraylist_get(alunknown, i);
	printf("index is %d, word is %s\n", i, word);
    }
}
