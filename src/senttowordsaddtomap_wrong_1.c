
#include <stdio.h>
#include <string.h>
#include "../lib/hashmap.h"

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

	char *stringlist[100];

	int stringListIndex = 0;

	struct hashmap *map = hashmap_new(sizeof(struct word), 0, 0, 0, 
                                     word_hash, word_compare, NULL, NULL);


	char *sentence = "tom make his first full score at the age of twenty";


	while(*sentence != '\0') {

		if ( *sentence == ' ' ) {

			hashmap_set(map, &(struct word){ .name= stringlist[ stringListIndex ], .count=10 });
			stringListIndex++;

			sentence++;
		}
		else {
			stringlist[ stringListIndex ] = *(sentence++);
//			stringlist[ stringListIndex ]++;

			/*
			if ( *sentence == '\0' ){
				int index = 0;
				while ( word[index] != '\0' ) {
					printf("%c", word[index]);
					index++;
				}
				printf("\n");
			}
			*/
		}
	}
	printf("\n");

        printf("\n-- iterate over all words (hashmap_iter) --\n");
        size_t iter = 0;
        void *item;
        while (hashmap_iter(map, &iter, &item)) {
           const struct word *word = item;
           printf("%s (count=%d)\n", word->name, word->count);
        }
}
