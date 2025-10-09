#include <stdio.h>
#include <stdlib.h>

#include "wordutil_v_2.h"
#define FILE_PATH "/home/jack/develop/c/word_parse/data/english/knownwords.txt"
void getdictionaryformtest(char *word);
int main() {
    /* FILE *f = fopen(FILE_PATH, "rb"); */

    /* arraylist *al = readwordsfromfile(f); */
    /* int size = arraylist_size(al); */
    /* for (int i = 0; i < size; i++) { */
    /* char *word = arraylist_get(al, i); */
    /* getdictionaryform(word); */
    /* printf("index is %d, a word in array list is %s\n", i, word); */
    /* } */
    char *a = calloc(50, sizeof(char));
    /* a = "watching"; */
    /* a = "actually"; */
    a[0] = 'l';
    a[1] = 'y';
    a[2] = 'i';
    a[3] = 'n';
    a[4] = 'g';

    getdictionaryformtest(a);
}
void getdictionaryformtest(char *word) {
    getdictionaryform(word);
    printf("word is %s\n", word);
}
