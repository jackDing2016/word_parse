
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../lib/stringutil.h"
int main() {
    char *gerund_suffix = "ing";
    char *word = calloc(50, sizeof(char));
    word = "hunting";
    char *p;
    p = word;
    int len = strlen(word);
    printf("len of a is %d\n", len);
    p = p + len - 3;
    printf("char is %c\n", *p);
    printf("string is %s\n", p);
    bool res = isequal(gerund_suffix, p);
    printf("res is equal: %d\n", res);
}
