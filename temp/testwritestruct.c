#include <stdio.h>
#include <stdlib.h>

#include "wordindex.h"
/* #include "/home/jack/develop/c/lib/string.h" */

void write();
void write_version2();
void write_version3();
/* void (char *name, int index); */
int main() {
    /* write(); */
    /* write_version2(); */
    write_version3();
}
void write() {
    /* FILE *f = fopen("jackding.txt", "wb"); */
    /* struct wordindex *wi = malloc(sizeof(struct wordindex)); */
    /* char *name = calloc(sizeof(char), 7); */
    /* strcpy(name, "monkey"); */
    /* wi->name = name; */
    /* wi->index = 10; */
    /* fwrite(wi->name, sizeof(char), strlen(name), f); */
    /* fwrite(&(wi->index), sizeof(int), 1, f); */

    /* struct wordindex *wi2 = malloc(sizeof(struct wordindex)); */
    /* char *name2 = calloc(sizeof(char), 7); */
    /* strcpy(name2, "millon"); */
    /* wi2->name = name2; */
    /* wi2->index = 11; */
    /* fwrite(wi2->name, sizeof(char), strlen(name2), f); */
    /* fwrite(&(wi2->index), sizeof(int), 1, f); */

    /* fclose(f); */
}
void write_version2() {
    FILE *f = fopen("jackding.txt", "wb");
    struct wordindex *wi = malloc(sizeof(struct wordindex));
    /* char *name = calloc(sizeof(char), 7); */
    /* strcpy(name, "monkey"); */
    /* wi->name = name; */
    struct string *name = newstr("monkey");
    wi->name = name;
    wi->index = 99;
    // lenth of string should be written before value of string
    fwrite(&(wi->name->length), sizeof(int), 1, f);
    fwrite(wi->name->value, sizeof(char), wi->name->length, f);
    fwrite(&(wi->index), sizeof(int), 1, f);

    /* struct wordindex *wi2 = malloc(sizeof(struct wordindex)); */
    /* char *name2 = calloc(sizeof(char), 7); */
    /* strcpy(name2, "millon"); */
    /* wi2->name = name2; */
    /* wi2->index = 11; */
    /* fwrite(wi2->name, sizeof(char), strlen(name2), f); */
    /* fwrite(&(wi2->index), sizeof(int), 1, f); */

    fclose(f);
}
void write_version3() {
    FILE *f = fopen("jackding.txt", "wb");
    struct wordindex *wi = newwordindex("monkey", 88);
    writewordindex(wi, f);
    struct wordindex *wi2 = newwordindex("sphere", 500);
    writewordindex(wi2, f);
    fclose(f);
}

