#include <stdio.h>
#include <string.h>


// The function returns a pointer to that character in s,
// or NULL if n <= 0 or no such occurrence of the character exists
char* strchrn(char* s, int c, int n)
{
    char* charOccur = NULL;
    int charCounter = 0;
    _Bool found = 0;

    while (found == 0 && *s != '\0') {
        if (*s == c) {
            charCounter++;
        }
        if (charCounter == n) {
            found = 1;
            charOccur = s;
        } else {
            s++;
        }
    }
    return charOccur;
}

int main(void)
{

    char* line = "This is a string";
    for (int n = 1; n <= 5; n++) {
        char* ptr = strchrn(line, 'i', n);
        if (ptr != NULL) {
            int index = ptr - line;
            printf("Occurrence %d of 'i' found at index = %d\n", n, index);
        } else {
            printf("Occurrence %d of 'i' not found\n", n);
        }
    }
}
