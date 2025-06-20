#include <stdio.h>
#include <string.h>
#include "hashmap.h"

struct user {
    char *name;
    int age;
};

int user_compare(const void *a, const void *b, void *udata) {
    const struct user *ua = a;
    const struct user *ub = b;
    return strcmp(ua->name, ub->name);
}

bool user_iter(const void *item, void *udata) {
    const struct user *user = item;
    printf("%s (age=%d)\n", user->name, user->age);
    return true;
}

uint64_t user_hash(const void *item, uint64_t seed0, uint64_t seed1) {
    const struct user *user = item;
    return hashmap_sip(user->name, strlen(user->name), seed0, seed1);
}

int main() {
    // create a new hash map where each item is a `struct user`. The second
    // argument is the initial capacity. The third and fourth arguments are 
    // optional seeds that are passed to the following hash function.
    struct hashmap *map = hashmap_new(sizeof(struct user), 0, 0, 0, 
                                     user_hash, user_compare, NULL, NULL);

    // Here we'll load some users into the hash map. Each set operation
    // performs a copy of the data that is pointed to in the second argument.
    hashmap_set(map, &(struct user){ .name="Dale", .age=44 });
    hashmap_set(map, &(struct user){ .name="Roger", .age=68 });
    hashmap_set(map, &(struct user){ .name="Jane", .age=47 });

    struct user *user; 
    
    printf("\n-- get some users --\n");
    user = hashmap_get(map, &(struct user){ .name="Jane" });
    printf("%s age=%d\n", user->name, user->age);

    user = hashmap_get(map, &(struct user){ .name="Roger" });
    printf("%s age=%d\n", user->name, user->age);

    user = hashmap_get(map, &(struct user){ .name="Dale" });
    printf("%s age=%d\n", user->name, user->age);

    user = hashmap_get(map, &(struct user){ .name="Tom" });
    printf("%s\n", user?"exists":"not exists");

    printf("\n-- iterate over all users (hashmap_scan) --\n");
    hashmap_scan(map, user_iter, NULL);

    printf("\n-- iterate over all users (hashmap_iter) --\n");
    size_t iter = 0;
    void *item;
    while (hashmap_iter(map, &iter, &item)) {
        const struct user *user = item;
        printf("%s (age=%d)\n", user->name, user->age);
    }

    hashmap_free(map);
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

