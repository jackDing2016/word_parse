#include <stdio.h>
#include <stdlib.h>

int main(){
	malloc(1);
	printf("abcde\n");

	int a = 10;
	int b = sizeof(a);
	printf("%d\n", b);


	int *p;

	p = calloc( 100, sizeof(int) );

	printf("%d", p);


}
