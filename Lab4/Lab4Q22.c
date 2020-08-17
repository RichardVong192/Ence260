#include <stdio.h>

char* mystrrchr(char* s, int c)

{
    char* lastCharOccur = 0;
    for (int i = 0; *s != '\0'; i++) {
        if (*s == c) {
            lastCharOccur = s;
        }
        s++;
    }
    return lastCharOccur;
}

int main(void)
{
    char* s = "ENCN305";
    char* foundAt = mystrrchr(s, 'E');
    if (foundAt == NULL) {
        puts("Not found");
    } else {
        printf("%zu\n", foundAt - s);
    }
}
