#include <stdio.h>

int main(void)
{
    int num = 20;
    int* ptr = NULL;
    ptr = &num;
    printf("%d\n", *ptr);

}
