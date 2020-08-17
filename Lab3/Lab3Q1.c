#include <stdio.h>

int main(void)
{

    char c = 0;
    //c = ' '; /* The RHS is a quote char, a space and another quote */
    //c = '\40';
    //c = 040;
    //c = 32;
    //c = 0x40;
    //c = '\32';
    //c = ''; /* The RHS is just two quote chars */
    //c = 0x20;
    //c = 40;

    printf("c is: '%c'\n", c);
}
