#include <stdio.h>

int main(void)
{
    int i = 10;
    int j = 20;
    int* p = NULL; // define NULL to be 0
    p = &i;
    *p = j;
    printf("i = %d, j = %d\n", i, j);
}
