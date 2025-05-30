#include <stdio.h>

char *getWord(){
	char *s = "abc";
	return s;
}

int main(){
	char word[100];

	char *sentence = "tom make his first full score at the age of twenty";
	
	char *w = getWord();

	char c;
	while ( ( c = *(w++) ) != '\0' ) {
		printf( "%c", c );
	}
	printf("\n");

}
