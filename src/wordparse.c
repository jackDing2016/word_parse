

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

int main() {

	FILE *file = fopen("/home/jack/develop/c/wordparse/test/testdata.txt", "r");

	char c ;	
	while((c = fgetc(file)) != EOF){
		printf("%c", c);	
	}


//    struct hashmap *map = hashmap_new(sizeof(struct word), 0, 0, 0, 
//                                     word_hash, word_compare, NULL, NULL);

//    hashmap_set(map, &(struct word){ .name="quae", .count=10 });
//    hashmap_set(map, &(struct word){ .name="cuis", .count=8 });
//    hashmap_set(map, &(struct word){ .name="em", .count=897 });

//    struct word *word; 
 /*   
    printf("\n-- get some words --\n");
    word = hashmap_get(map, &(struct word){ .name="quae" });
    printf("%s word=%d\n", word->name, word->count);

    word = hashmap_get(map, &(struct word){ .name="cuis" });
    printf("%s word=%d\n", word->name, word->count);

    word = hashmap_get(map, &(struct word){ .name="em" });
    printf("%s word=%d\n", word->name, word->count);

    word = hashmap_get(map, &(struct word){ .name="Tom" });
    printf("%s\n", word?"exists":"not exists");

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

    */
}

// output:
// -- get some users --
// Jane age=47
// Roger age=68
// Dale age=44
// not exists
// 
// -- iterate over all users (hashmap_scan) --
// Dale (age=44)
// Roger (age=68)
// Jane (age=47)
//
// -- iterate over all users (hashmap_iter) --
// Dale (age=44)
// Roger (age=68)
// Jane (age=47)


