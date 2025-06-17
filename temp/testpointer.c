#include <stdio.h>

int main() {
	
	char *contents = "Pointer is an difficult knowledge to understand";

    for (char* p = contents; *p; ) {
        // Skip whitespace.
	printf( "p value is %c\n", *p );
     /* 
       	while (*p && *p <= ' ') {
            p++;
        }
	*/
    //    char* word = p;

        // Find end of word.
       /*
       	while (*p && *p > ' ') {
            p++;
        }
        if (*p != 0) {
            *p = 0;
            p++;
        }
*/
    }
	
}
