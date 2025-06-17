
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

int isexist( struct word *wp[], char *str ); 
void printword(int s, int e, char *source);

void getword( char str[], int s, int e, char *source );
void iteratewordptr( struct word *wp[] );

char *popword( int s, int e, char *source );

char *alloc( int n );

struct word *wordptr[ 10 ];

int isequal( char *a, char *b );
struct word *getwordbyname( struct word *wp[], char *str ); 

int sizeofarr( struct word *wp[] );

int main(){

	char *sentence = "we have a lot of task to do";

	char *currentp;

	char *wordsource[ 100 ];

	char ch;

	int startIndex = 0;
	int endIndex = 0;

	currentp = sentence;

	int currentIndex = 0;

//	char word[50];

	struct word *pwo;

	int wordIndex = 0;

	while ( ( ch = *(currentp++ ) ) != '\0' ) {
		if ( ch == ' ' ) {

			char *aword = popword( startIndex, endIndex, sentence );

			printf("a word is %s\n", aword);

			/* if "aword" that has already exist in array, increase the 
			 * count of it
			 *
			 * if not insert the new word, and the count is 1
			*/

//			int ishaveword = isexist( wordptr, aword );
			// not exist
//			if (ishaveword == 2) {
				pwo = ( struct word * ) malloc( sizeof( struct word ) );
				pwo -> name = aword;
				pwo -> count = 1;
				wordptr[ wordIndex ] = pwo;
				wordIndex++;
				startIndex = endIndex + 1;

//				int arraysize = sizeofarr( wordptr );
				int arraysize = sizeof( wordptr );
				printf( "after add word size of arra is %d\n", arraysize );

//			}
//			else if ( ishaveword == 1 ) {
				
//			}
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
	char *res = alloc( 100 );
	for( int i = s; i < e; i++ ) {
	//	printf("%c", source[ i ]);
		res[ i - s ] = source[ i ];
	}
	return res;

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

	/**
	 * if not exists return a null string which is a solution for temporary
	 */
//	struct word *nullword = ( struct word * ) malloc( sizeof( struct word ) );
//	nullword -> name = "null" ;
//	return nullword;
}

// 1-exist 2-not exist 
int isexist( struct word *wp[], char *str ) {

	printf( "aa\n" );	
	struct word *x = getwordbyname( wp, str );

	printf( "bb\n" );
	int aa = isequal( x -> name, "null" );

	if ( aa == 1 ) {
		return 2;
	}	
	else {
		return 1;
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
		
	} while ( (*a != '\0') && ( *b != '\0') );
	return 1;

}

/*

int sizeofarr( struct word *wp[] ) {
	int res = 0;

	struct word *p = *wp;

	while( p++ ){
		res++;
	}

	return res;

}
*/

int sizeofarr( struct word *wp[] ){
	return sizeof( wp ) / sizeof( wp[0] );
}
