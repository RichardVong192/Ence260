#include <stdio.h>

void swap(int* pi, int* pj)
{
    int temp = *pi;
    *pi = *pj;
    *pj = temp;

}

int main(void)
{
    int i = 10, j = 20;
    swap(&i, &j);
    printf("%d %d\n", i, j);
}
