
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "wordindex.h"

void read();
void read_version2();
void read_version3();
int main() {
    /* read(); */
    /* read_version2(); */
    read_version3();
}
void read() {
    /* FILE *f = fopen("jackding.txt", "rb"); */
    /* struct wordindex *wi = malloc(sizeof(struct wordindex)); */
    /* wi->name = calloc(20, sizeof(char)); */
    /* fread(wi->name, sizeof(char), 6, f); */
    /* fread(&(wi->index), sizeof(int), 1, f); */
    /* printf("name of word is %s\n", wi->name); */
    /* printf("index of word is %d\n", wi->index); */

    /* struct wordindex *wi2 = malloc(sizeof(struct wordindex)); */
    /* wi2->name = calloc(20, sizeof(char)); */
    /* fread(wi2->name, sizeof(char), 6, f); */
    /* fread(&(wi2->index), sizeof(int), 1, f); */
    /* printf("name of word is %s\n", wi2->name); */
    /* printf("index of word is %d\n", wi2->index); */

    /* fclose(f); */
}
void read_version2() {
    FILE *f = fopen("jackding.txt", "rb");
    struct wordindex *wi = malloc(sizeof(struct wordindex));
    wi->name = malloc(sizeof(struct string));
    fread(&(wi->name->length), sizeof(int), 1, f);
    wi->name->value = calloc(wi->name->length, sizeof(char));
    fread(wi->name->value, sizeof(char), wi->name->length, f);
    fread(&(wi->index), sizeof(int), 1, f);
    printf("name of word is %s\n", wi->name->value);
    printf("index of word is %d\n", wi->index);

    fclose(f);
}
void read_version3() {
    FILE *f = fopen("jackding.txt", "rb");
    struct wordindex *wi = readwordindex(f);
    struct wordindex *wi2 = readwordindex(f);
    printf("name of word is %s\n", wi->name->value);
    printf("index of word is %d\n", wi->index);
    printf("name of word is %s\n", wi2->name->value);
    printf("index of word is %d\n", wi2->index);
}
