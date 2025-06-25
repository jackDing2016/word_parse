#include <stdio.h>
#include "../lib/stringutil.h"
int main(){
	char *a = "peter";
	char *b = "peter";
	bool val  = isequal( a, b );
	printf( "values is %d\n", val );	
	if( val == true ) {
		printf( "equal\n" );
	}
	else {
		printf( "not equal\n" );

	}
}
