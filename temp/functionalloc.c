#include <stdio.h>

static long int allocbuf[ 10000 ];

static long int *allocp = allocbuf;

int main() {
	printf("%d\n", allocp);

	allocp = allocp + 2;

	printf( "%d\n", allocp - allocbuf );

}



