#include <stdio.h>

int main() {
	int length  = 10;
	printf( "length is %d\n", length );
	setlength( &length );	
	printf( "after update length is %d\n", length );

	*(&length) = 30;
	printf( "after update direct without function length is %d\n", length );

}

void setlength( int *plength ){
	*plength = 20;
}
