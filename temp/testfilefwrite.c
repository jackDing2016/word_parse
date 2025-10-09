#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    char *a = "abc";

    /* char **arr = calloc(10, sizeof(char *)); */
    char **arr = malloc(sizeof(*arr) * 10);
    char *str1 = calloc(20, sizeof(char));
    strcpy(str1, "child");
    char *str2 = calloc(20, sizeof(char));
    strcpy(str2, "monkey");
    *arr = str1;
    *(arr + 1) = str2;
    /* *arr = calloc(20, sizeof(char)); */
    /* *arr = 'a'; */

    for (int i = 0; i < 10; i++) {
	printf("str is %s\n", *(arr + i));
    }

    FILE *f = fopen("jackding.txt", "w");
    /* fwrite(arr, 1, sizeof(arr), f); */
    /* fwrite(arr, sizeof(char) * 20, 10, f); */
    /* fwrite(arr, 1, 2, f); */
    
}
