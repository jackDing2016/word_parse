#include <stdio.h>

#include "testlist.h"

int main() {
    struct arraylist *al = createarraylist();
    addelement( al, "happy" );	
    addelement( al, "good" );	
    addelement( al, "grateful" );	
    addelement( al, "fasinating" );	
    addelement( al, "change" );	
    addelement( al, "large" );
    addelement( al, "boy" );	
    addelement( al, "smile" );	
    addelement( al, "function" );	
    addelement( al, "nothing" );	
    addelement( al, "people" );	

    iteratearraylist( al );

    /* int sizeofal = size( al ); */
    /* printf( "size of al is %d\n", sizeofal ); */

    char *aword = "good";
    bool iscon = iscontainelement( al, aword );
    printf( "iscon value is %d\n", iscon );

    char *bword = getelement( al, 0 );
    printf( "get word of index 0 is %s\n", bword );

}
