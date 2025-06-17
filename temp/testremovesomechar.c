#include <stdio.h>
#include <ctype.h>
#include <string.h>

void removeNonAlphanumeric(char *str) {
    int j = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i])) {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}

int main() {
    char str[] = "Hello! 123 World.";
    removeNonAlphanumeric(str);
    printf("Filtered String: %s\n", str);
    return 0;
}
