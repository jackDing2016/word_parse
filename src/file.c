#include <stdio.h>

int main(){
	FILE *f = fopen("/home/jack/develop/c/wordparse/test/testdata.txt", "r");
     int ch;
     while ((ch = fgetc(f)) != EOF) {

	     //if ( ch == ' ') {
	     printf("%c", ch);
	     //}
     }	
}
