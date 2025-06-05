
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
typedef struct wordobject {
	char *name;
	int count;
} wo;
*/
struct wordobject {
	char *name;
	int count;
};


void printword(int s, int e, char *source);

void getword( char str[], int s, int e, char *source );
// void iteratewordobjectptr( wo *wop[] );
void iteratewordobjectptr( struct wordobject *wop[] );

void iteratewordptr( char *wptr[] );

char *alloc( int n );

char *wordptr[ 100 ];


struct wordobject *wordobjectptr[ 100 ];


int main(){

	char *sentence = "we have a lot of task to do";

	char *currentp;

	char *wordsource[ 100 ];
//	char *wordptr[ 100 ];

	char ch;

	int startIndex = 0;
	int endIndex = 0;

	currentp = sentence;

	int currentIndex = 0;

	char word[50];

	char *p;

	struct wordobject *pwo;

	int wordIndex = 0;

	while ( ( ch = *(currentp++ ) ) != '\0' ) {
		if ( ch == ' ' ) {
		//	printword( startIndex, endIndex, sentence );
			getword( word, startIndex, endIndex, sentence );
			printf( "word is %s\n", word );
		
			p = alloc( 100 );	

			// to do allocat pwo memory


			pwo = ( struct wordobject * ) malloc( sizeof( struct wordobject ) );	

			strcpy( p, word );
			wordptr[ wordIndex ] = p; 

//			strcpy( pwo -> name, word );

			char *c = alloc( 100 );

			strcpy( c, word );

			pwo -> name = c;
			pwo -> count = 1;

			wordobjectptr[ wordIndex ] = pwo;

			wordIndex++;

			startIndex = endIndex + 1;
		}
		endIndex++;
	}

	// iterate wordptr
	for ( int i = 0; i < 10; i++ ){
	//	printf( "%s\n", wordptr[i] );
	}
	
	// iterate wordptr by function
//	iteratewordptr( wordptr );

	// iterate wordobject by function 
	iteratewordobjectptr( wordobjectptr );  

	/*
	for ( int i = 0; i < 5; i++ ){
		printf( "%s: %d\n", wordobjectptr[ i ] -> name, wordobjectptr[ i ] -> count );
	}
*/
}

void getword( char str[], int s, int e, char *source ) {
	for( int i = s; i < e; i++ ) {
	//	printf("%c", source[ i ]);
		str[ i - s ] = source[ i ];
	}
	str[ e - s ] = '\0';
//	printf( "word is %s\n", str );

}

void printword( int s, int e, char *source ) {
	for( int i = s; i < e; i++ ) {
		printf("%c", source[i]);
	}
	printf("\n");

}

static char allocbuf[ 10000 ];
static char *allocp = allocbuf;

char *alloc( int n ) {
	allocp += n;
	return allocp - n;
}

void iteratewordobjectptr( struct wordobject *wop[] ) {

//void iteratewordobjectptr( wo *wop[] ) {

	for ( int i = 0; i < 5; i++ ) {

//		wo *w = wop[ i ];

		struct wordobject *w = wop[ i ];

		printf( "%s: %d\n", w -> name, w -> count );

//		struct wordobject *a = wop[ i ];
//		printf( "%s", a -> name );

	}

}

void iteratewordptr( char *wptr[]  ) {
	for ( int i = 0; i < 5; i++) {
//		printf( "%s: %d\n", wptr[ i ] -> name, wptr[ i ] -> count );

	}  
}










