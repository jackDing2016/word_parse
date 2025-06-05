#include <stdio.h>
#include <string.h>
#include "../lib/hashmap.h"

void printword(int s, int e, char *source);

void getword( char str[], int s, int e, char *source );

void mystrcpy( char *dp, char *sp );

char *alloc( int n );

char *wordptr[ 100 ];

struct word {
    char *name;
    int count;
};

int word_compare(const void *a, const void *b, void *udata) {
    const struct word *ua = a;
    const struct word *ub = b;
    return strcmp(ua->name, ub->name);
}

bool word_iter(const void *item, void *udata) {
    const struct word *word = item;
    printf("%s (count=%d)\n", word->name, word->count);
    return true;
}

uint64_t word_hash(const void *item, uint64_t seed0, uint64_t seed1) {
    const struct word *word = item;
    return hashmap_sip(word->name, strlen(word->name), seed0, seed1);
}


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
			getword( word, startIndex, endIndex, sentence );
			printf( "word is %s\n", word );
		
			p = alloc( 100 );	

		//	strcpy( p, word );
			mystrcpy( p, word );
			wordptr[ wordIndex++ ] = p; 

			startIndex = endIndex + 1;
		}
		endIndex++;
	}
    

	struct hashmap *map = hashmap_new(sizeof(struct word), 0, 0, 0, 
                                     word_hash, word_compare, NULL, NULL);



	// iterate wordptr
	for ( int i = 0; i < 5; i++ ){
		printf( "%s\n", wordptr[i] );
	    	hashmap_set(map, &(struct word){ .name=wordptr[i], .count=10 });
	
	}
    printf("\n-- iterate over all words (hashmap_scan) --\n");
    hashmap_scan(map, word_iter, NULL);

    printf("\n-- iterate over all words (hashmap_iter) --\n");
    size_t iter = 0;
    void *item;
    while (hashmap_iter(map, &iter, &item)) {
        const struct word *word = item;
        printf("%s (count=%d)\n", word->name, word->count);
    }

    hashmap_free(map);

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

void mystrcpy( char *dp, char *sp ) {

	while ( ( *dp  = *sp ) != '\0'  ) {
		dp++;
		sp++;
	}

}
