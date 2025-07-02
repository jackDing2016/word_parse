#include <stdio.h>
/* #include "testlist.h" */
#include "wordutil.h"


int main(){
    /* struct arraylist *alknown = createarraylist(); */
    /* addelement( alknown, "size" ); */
    /* addelement( alknown, "page" ); */
    /* addelement( alknown, "next" ); */
    /* addelement( alknown, "fan" ); */
    /* addelement( alknown, "send" ); */
    /* addelement( alknown, "color" ); */
    /* addelement( alknown, "height" ); */
    /* struct arraylist *alsource = createarraylist(); */
    /* addelement( alsource, "fan" ); */
    /* addelement( alsource, "manual" ); */
    /* addelement( alsource, "help" ); */
    /* addelement( alsource, "guity" ); */
    /* addelement( alsource, "future" ); */
    /* addelement( alsource, "fight" ); */
    FILE *fknownwords = fopen( "/home/jack/develop/c/wordparse/data/english/knownwords.txt_back" ,"rb" );
    struct arraylist *alknown = readwordsfromfile( fknownwords );
    FILE *fsource = fopen( "/home/jack/develop/c/wordparse/data/english/asubdata.txt", "rb" );
    struct arraylist *alsource = readwordsfromfile( fsource );
    int sizesourceal = getsize( alsource );
    struct arraylist *alunknown = createarraylist();
    for ( int i = 0; i < sizesourceal; i++ ) {
	char *element = getelement( alsource, i );
	if( iscontainelement(alknown, element) == false ) {
	    addelement( alunknown, element );
	}
    }
    iteratearraylist( alunknown );
}
