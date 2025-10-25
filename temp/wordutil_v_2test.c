#include <stdio.h>

#include "wordutil_v_2.h"

void getknownwordlisttest();

int main() {
    /* aa */
    getknownwordlisttest();
}

void getknownwordlisttest() {
    arraylist *l = getknownwordlist();
    for (int i = 0; i < arraylist_size(l); i++) {
	printf("word is %s\n", arraylist_get(l, i));
    }
}

