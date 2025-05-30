#include <stdio.h>

int main(){
	FILE *f = fopen("/home/jack/data.txt", "r");
     int ch;
     while ((ch = fgetc(f)) != EOF) {
	     if ( ch == ' ') {
	     printf("%c", 'a');
	     }
     }	
}
