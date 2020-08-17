#include <stdio.h>

int tokenCopy(char* dest, const char* src, int destSize)
{
    int i = 0;

    while (*(src + i) != '\0' && i < (destSize - 1) && *(src + i) != ' ') {
        *(dest + i) = *(src + i);
        i++;
    }
    *(dest + i) = '\0';
    return i;
}

int main(void)
{
    char buff[10];
    int n = tokenCopy(buff, " ", 10);
    printf("%d '%s'\n", n, buff);


    char buff1[3];
    int n1 = tokenCopy(buff1, "This is a string", 3);
    printf("%d '%s'\n", n1, buff1);
}
