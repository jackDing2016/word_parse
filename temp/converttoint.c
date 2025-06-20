#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main(){
	char *a = "100";
	int b = 855;
	int c = atoi(a);
	if ( c > b  ) {
		printf( "yes you are bigger" );
	}
}
