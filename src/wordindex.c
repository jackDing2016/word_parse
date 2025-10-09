#include "wordindex.h"

#include <stdio.h>
#include <stdlib.h>
struct wordindex *newwordindex(char *name, int startindex, int endindex) {
    struct wordindex *wi = malloc(sizeof(struct wordindex));
    struct string *n = newstr(name);
    wi->name = n;
    wi->startindex = startindex;
    wi->endindex = endindex;
    return wi;
}
void writewordindex(struct wordindex *w, FILE *f) {
    // lenth of string should be written before value of string
    fwrite(&(w->name->length), sizeof(int), 1, f);
    fwrite(w->name->value, sizeof(char), w->name->length, f);
    fwrite(&(w->startindex), sizeof(int), 1, f);
    fwrite(&(w->endindex), sizeof(int), 1, f);
}
struct wordindex *readwordindex(FILE *f) {
    struct wordindex *wi = malloc(sizeof(struct wordindex));
    wi->name = malloc(sizeof(struct string));
    fread(&(wi->name->length), sizeof(int), 1, f);
    wi->name->value = calloc(wi->name->length, sizeof(char));
    fread(wi->name->value, sizeof(char), wi->name->length, f);
    fread(&(wi->startindex), sizeof(int), 1, f);
    fread(&(wi->endindex), sizeof(int), 1, f);
    return wi;
}
