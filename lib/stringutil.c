#include <stdio.h>
#include "stringutil.h"
#include <stdbool.h>
bool isequal( char *a, char *b ) {
	// 1-equal 2-not equal
	do {
		if( *a != *b ) {
			return false;
		} 
		else if ( *a == '\0' || *b == '\0' ) {
			return false;
		}
		a++;
		b++;
		
	} while ( (*a != '\0') && ( *b != '\0') );
	return true;
}



