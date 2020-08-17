#include <stdio.h>
#include <stdio.h>

size_t mystrlen(const char* s)
{
    int i = 0;
    while (*s != '\0') {
        s++;
        i++;
    }
    return i;

}



int main(void)
{
    printf("%zd\n", mystrlen("ENCE260"));

}
