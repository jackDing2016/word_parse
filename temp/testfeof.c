#include <stdio.h>

#include "wordindex.h"
int main() {
    FILE *f = fopen("jackding.txt", "rb");
    /* while (feof(f) != 0) { */
    while (!feof(f)) {
	struct wordindex *w = readwordindex(f);
	printf("index of %s is %d\n", w->name->value, w->index);
    }
}
