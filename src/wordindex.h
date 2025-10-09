#include <stdio.h>

#include "/home/jack/develop/c/lib/string.h"
struct wordindex {
    /* char *name; */
    /* char name[20]; */
    struct string *name;
    int startindex;
    int endindex;
};

struct wordindex *newwordindex(char *name, int startindex, int endindex);

void writewordindex(struct wordindex *w, FILE *f);
struct wordindex *readwordindex(FILE *f);
