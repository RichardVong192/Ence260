#include <stdio.h>

int main(void)
{

    char buff[100];
    int c;
    int i = 0;
    while ((c = getchar()) != '\n' && i < 100) {
        buff[i++] = c;
    }

}
