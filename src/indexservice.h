#include <stdio.h>

#include "/home/jack/develop/c/lib/datastructs-c/arraylist.h"
#include "/home/jack/develop/c/lib/datastructs-c/hashtable.h"
/* struct string { */
/*     char *value; */
/*     int length; */
/* }; */

arraylist *buildindex();
arraylist *buildindex_version2();

// save index to file
void saveindex(arraylist *indexlist);
arraylist *loadindex();
hashtable *loadindextable();
bool justtest();
