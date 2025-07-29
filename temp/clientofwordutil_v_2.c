#include <stdio.h>

#include "wordutil_v_2.h"
#define FILE_PATH \
    "/home/jack/develop/c/word_parse/data/english/knownwords.txt"
int main() {
    FILE *f = fopen(FILE_PATH, "rb");

    arraylist *al = readwordsfromfile(f);
    int size = arraylist_size(al);
    for (int i = 0; i < size; i++) {
	char *word = arraylist_get(al, i);
	/* getdictionaryform(word); */
	printf("index is %d, a word in array list is %s\n", i, word);
    }
}
