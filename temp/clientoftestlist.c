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

	iteratearraylist( al );

	int *sizeofal = size( al );
	printf( "size of al is %d\n", *sizeofal );
}
