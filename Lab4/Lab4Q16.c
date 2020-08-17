#include <stdio.h>

int main(void)
{

    char* s = "Ummm: ";

    while (*s) {
        putchar(*s++);
    }
    printf("s[0] = %c", s[0]);
}
