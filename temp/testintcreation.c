#include <stdio.h>
#include <stdlib.h>

int main() {
	int *a;
	a = malloc( sizeof(int) );
	*a = 10;
	int b = 5;	
	printf( "*a is %d\n", *a );		
	printf( "b is %d\n", b );	
	*a = *a + 1;
	printf( "*a is %d\n", *a );		
	
}
