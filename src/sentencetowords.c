#include <stdio.h>

int main(){
	
	char word[100];

	char *sentence = "tom make his first full score at the age of twenty";

	int currentIndex = 0;

	while(*sentence != '\0') {

		if ( *sentence == ' ' ) {
			int index = 0;
			while ( word[index] != '\0' ) {
				printf("%c", word[index]);
				index++;
			}
			printf("\n");



			currentIndex = 0;
			for(int i = 0; i < 100; i++){
				word[i] = '\0';
			}
			sentence++;
		}
		else {
			word[ currentIndex++ ] = *(sentence++);

			if ( *sentence == '\0' ){
				int index = 0;
				while ( word[index] != '\0' ) {
					printf("%c", word[index]);
					index++;
				}
				printf("\n");
			}
		}
	}
	printf("\n");

}
