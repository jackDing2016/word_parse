#include <stdio.h>

char *allocp( int n );

char data[90000];
char *p;

int main(){
	FILE *f = fopen("/home/jack/develop/c/wordparse/test/testdata.txt", "r");
     	int ch;
	int index = 0;
     	while ((ch = fgetc(f)) != EOF) {

		p = allocp( 2 );
		*p = ch;
		data[ index++ ] = ch;	
	    	 //if ( ch == ' ') {
//	    	 printf("%c", ch);
	    	 //}
    	 }

	// iterate data array	
/*
	char c;
	while ( ( c = *p) != '\0' ) {
		p++;
		printf( "%c", c );
	}
	printf( "%s", data );

	*/
}


static char space[ 90000 ];
static char *ap = space;
char *allocp( int n ) {

	ap = ap + n;
	return ap - n;

}
