#include <stdio.h>

int main(){

	FILE *fp = fopen( "/home/jack/test.txt", "w" );
	putc( 'y', fp );
	putc( 'e', fp );
	putc( 's', fp );
	putc( '\n', fp );
	putc( 'h', fp );
	putc( 'o', fp );
	putc( 'w', fp );

}
