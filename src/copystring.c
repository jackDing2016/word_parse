#include <stdio.h>


void copy_version_a_2( char *source, char *dest  ) {
	while( ( *dest = *source) != '\0' ){
		dest++;
		source++;

	}
}


int main(){

	char *you = "jack";

	char *youcopy = "a";
	copy_version_a_2(you, youcopy);
/*
	char ch;	
	while ( (ch = *youcopy ) != '\0' ) {
		printf( "%c", ch );
		youcopy++;
	}
	printf( "\n" );
*/
}



