#include <stdio.h>
#include <string.h>

void printword(int s, int e, char *source);

void getword( char str[], int s, int e, char *source );

char *alloc( int n );

char *wordptr[ 100 ];

int main(){

	char *sentence = "we have a lot of task to do";

	char *currentp;

	char *wordsource[ 100 ];
	char *wordptr[ 100 ];

	char ch;

	int startIndex = 0;
	int endIndex = 0;

	currentp = sentence;

	int currentIndex = 0;

	char word[50];

	char *p;

	int wordIndex = 0;

	while ( ( ch = *(currentp++ ) ) != '\0' ) {
		if ( ch == ' ' ) {
		//	printword( startIndex, endIndex, sentence );
			getword( word, startIndex, endIndex, sentence );
			printf( "word is %s\n", word );
		
			p = alloc( 100 );	

//			char p[ 100 ];
			strcpy( p, word );
			wordptr[ wordIndex++ ] = p; 

			startIndex = endIndex + 1;
		}
		endIndex++;
	}

	// iterate wordptr
	for ( int i = 0; i < 10; i++ ){
		printf( "%s\n", wordptr[i] );
	}

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

