#include <stdio.h>

void printword(int s, int e, char *source);

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

//	while ( ( ch = sentence[ currentIndex++ ] ) != '\0' ) {
//		printf( "%c\n", ch );
//		
//	}

	while ( ( ch = *(currentp++ ) ) != '\0' ) {
		if ( ch == ' ' ) {
			printword( startIndex, endIndex, sentence );
			startIndex = endIndex + 1;
		}
		endIndex++;
	}
}



void printword( int s, int e, char *source ) {
	for( int i = s; i < e; i++ ) {
		printf("%c", source[i]);
	}
	printf("\n");

}

