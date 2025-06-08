
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
typedef struct wordobject {
	char *name;
	int count;
} wo;
*/
struct word {
	char *name;
	int count;
};


void printword(int s, int e, char *source);

void getword( char str[], int s, int e, char *source );
void iteratewordptr( struct word *wp[] );

char *popword( int s, int e, char *source );

char *alloc( int n );


struct word *wordptr[ 100 ];


int isequal( char *a, char *b );
struct word *getwordbyname( struct word *wp[], char *str ); 

int main(){

	char *sentence = "we have a lot of task to do";

	char *currentp;

	char *wordsource[ 100 ];

	char ch;

	int startIndex = 0;
	int endIndex = 0;

	currentp = sentence;

	int currentIndex = 0;

	char word[50];

	struct word *pwo;

	int wordIndex = 0;

	while ( ( ch = *(currentp++ ) ) != '\0' ) {
		if ( ch == ' ' ) {
			getword( word, startIndex, endIndex, sentence );
		
			pwo = ( struct word * ) malloc( sizeof( struct word ) );	

			char *c = alloc( 100 );

			strcpy( c, word );

			pwo -> name = c;
			pwo -> count = 1;

			wordptr[ wordIndex ] = pwo;

			wordIndex++;

			startIndex = endIndex + 1;
		}
		endIndex++;
	}

	// iterate wordobject by function 
	iteratewordptr( wordptr );  

	char *a = "jack";
	char *b = "rose";
	printf( "%d\n", isequal( a, b ) );
	printf( "%d\n", isequal( "jack", "jack" ) );

	struct word *matchedword = getwordbyname( wordptr, "lot" );
	printf( "name is %s, count is %d\n", matchedword -> name, matchedword -> count );

}

void getword( char str[], int s, int e, char *source ) {
	for( int i = s; i < e; i++ ) {
	//	printf("%c", source[ i ]);
		str[ i - s ] = source[ i ];
	}
	str[ e - s ] = '\0';
//	printf( "word is %s\n", str );

}

char *popword( int s, int e, char *source ) {
	char *res 
}

void printword( int s, int e, char *source ) {
	for( int i = s; i < e; i++ ) {
		printf("%c", source[i]);
	}
	printf("\n");

}

static char allocbuf[ 100000 ];
static char *allocp = allocbuf;

char *alloc( int n ) {
	allocp += n;
	return allocp - n;
}

void iteratewordptr( struct word *wp[] ) {

	for ( int i = 0; i < 5; i++ ) {

		struct word *w = wp[ i ];

		printf( "%s: %d\n", w -> name, w -> count );

	}

}

struct word *getwordbyname( struct word *wp[], char *str ) {
	
	for ( int i = 0; i < 5; i++ ) {

		struct word *w = wp[ i ];

		printf( "%s: %d\n", w -> name, w -> count );

		if ( isequal ( w -> name, str  ) == 1) {
			 return w;
		}

	}

}

int isequal( char *a, char *b ) {

	// 1-equal 2-not equal

	do {
		if( *a != *b ) {
			return 2;
		} 
		else if ( *a == '\0' || *b == '\0' ) {
			return 2;
		}

		a++;
		b++;
		
	} while ( (*a != '\0') || ( *b != '\0') );
	return 1;

}
