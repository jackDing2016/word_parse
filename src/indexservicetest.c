#include "indexservice.h"

/* #include "/home/jack/develop/c/lib/datastructs-c/arraylist.h" */
#include "wordindex.h"
void buildindextest();

void saveindextest();
void loadindextest();
void loadindextabletest();
int main() {
    /* buildindextest(); */
    /* saveindextest(); */
    loadindextest();
    /* loadindextabletest(); */
}

void buildindextest() {
    arraylist *wordindexlist = buildindex();
    unsigned int size = arraylist_size(wordindexlist);
    printf("size of index list is %d\n", size);
    for (int i = 0; i < size; i++) {
	struct wordindex *w = arraylist_get(wordindexlist, i);
	printf(" %s startindex: %d endindex: %d\n", w->name->value,
	       w->startindex, w->endindex);
    }
}
void saveindextest() {
    arraylist *w = buildindex();
    saveindex(w);
}
void loadindextest() {
    arraylist *l = loadindex();
    for (int i = 0; i < arraylist_size(l); i++) {
	struct wordindex *w = arraylist_get(l, i);
	printf(" %s startindex: %d endindex: %d\n", w->name->value,
	       w->startindex, w->endindex);
    }
}
void loadindextabletest() {
    char *a = "<kit>";
    hashtable *t = loadindextable();
    struct wordindex *w = hashtable_get(t, a);
    printf(" %s startindex: %d endindex: %d\n", w->name->value, w->startindex,
	   w->endindex);
}
