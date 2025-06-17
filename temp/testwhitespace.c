#include <stdio.h>
#include <stdlib.h>
int main() {

	char *a = malloc( sizeof(char) );
	*a = ' ';
	printf( "%c\n", *a );
		printf( "%d\n", *a );
}
