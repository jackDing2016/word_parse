#include <stdio.h>
#include <stdlib.h>

int main() {
	char *a[10];
	a[0] = malloc( sizeof(char) );
	*a[0] = 'c';
	if( a[1] ) {
		printf( "a[1] is not null\n" );
	}
	else {
		printf( "a[1] is null\n " );
	}
	// perform memory for a[1]
	a[1] = malloc( sizeof(char) );
	if( a[1] ) {
		printf( "a[1] is not null\n" );
	}
	else {
		printf( "a[1] is null\n " );
	}

}
