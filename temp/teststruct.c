#include <stdio.h>

struct word {
	char *name;
	int count;
};

struct word *wordalloc( int n );

struct word *wordlist[ 10 ];

int main() {

	struct word *a;
//	a = wordalloc( 1 );
	a -> count  = 10;
	a -> name = "quae";

	wordlist[0] = a;

	for ( int i = 0; i < 3; i++ ) {
		struct word *t = wordlist[ i ];
		printf( "%s\n", t -> name );
	}

}

static struct word allocbuf[ 500 ];
static struct word *allocp = allocbuf;

struct word *wordalloc( int n ) {
	allocp += n;
	return allocp - n;
}

