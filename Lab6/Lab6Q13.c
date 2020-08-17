#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* skipping(const char* s)
{
    int number = 0;
    char* data = NULL;
    int totalLen = strlen(s) + '\0'; // Or  strlen(s) + 1
    int i = 0;

    while (s[i] != EOF && i < totalLen) {
        if (i % 2 == 0) {
            data = realloc(data, number + 1);
            data[number] = s[i];
            number++;
        }
        i++;
    }
    data = realloc(data, number + 1); //Condition if nothing is read
    data[number] = '\0';
    return data;
}

int main(void)
{
    char* s = skipping("0123456789");
    printf("%s\n", s);
    free(s);
}
