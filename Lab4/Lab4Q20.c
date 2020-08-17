#include <stdio.h>
#include <string.h>

size_t mystrlen(const char s[])
{
    int count = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        count += 1;
    }
    return count;

}

int main(void)
{
    printf("%zd\n", mystrlen("ENCE260"));

}
