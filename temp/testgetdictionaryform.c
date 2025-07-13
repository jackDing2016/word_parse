#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void getdictionaryform(char *word);
int main() {
    /* char *origin = "cats"; */
    char *origin = calloc(50, sizeof(char));
    origin[0] = 'c';
    origin[1] = 'e';
    origin[2] = 'r';
    origin[3] = 't';
    origin[4] = 'a';
    origin[5] = 'i';
    origin[6] = 'n';
    origin[7] = 'l';
    origin[8] = 'y';

    /* origin = "cats"; */
    printf("origin word is %s\n", origin);
    getdictionaryform(origin);
    printf("the word of dictionary form is %s\n", origin);
}
void getdictionaryform(char *word) {
    int len = strlen(word);
    /* ed past tense form of a verb */
    /* s plural form of a noun */
    /* ly an adverb which derived from an adjective */
    char lastalphabet = word[len - 1];
    char lastsecondalphabet = word[len - 2];
    if (lastalphabet == 'd') {
	if (lastsecondalphabet == 'e') {
	    // cut it
	    word[len - 1] = '\0';
	    word[len - 2] = '\0';
	}
    } else if (lastalphabet == 'y') {
	if (lastsecondalphabet == 'l') {
	    // cut it
	    word[len - 1] = '\0';
	    word[len - 2] = '\0';
	}
    } else if (lastalphabet == 's') {
	if (lastsecondalphabet == 'e') {
	    // cut it
	}
    }
    /* printf("len is %d\n", a); */
    /* word[a - 1] = '\0'; */
}

