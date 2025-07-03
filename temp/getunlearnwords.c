#include <stdio.h>
/* #include "testlist.h" */
#include "wordutil.h"

#define KNOWNWORDSFILEPATH "/home/jack/develop/c/wordparse/data/english/knownwords.txt" 

int main(){
    FILE *fknownwords = fopen( KNOWNWORDSFILEPATH,"rb" );
    struct arraylist *alknown = readwordsfromfile( fknownwords );
    FILE *fsource = fopen( "/home/jack/develop/c/wordparse/data/english/asubdata.txt", "rb" );
    struct arraylist *alsource = readwordsfromfile( fsource );
    int sizesourceal = getsize( alsource );
    struct arraylist *alunknown = createarraylist();
    for ( int i = 0; i < sizesourceal; i++ ) {
	char *element = getelement( alsource, i );
	if ( *element != '\0' ) {
	    if( iscontainelement(alknown, element) == false ) {
		addelement( alunknown, element );
	    }
	}	
    }
    iteratearraylist( alunknown );
}
