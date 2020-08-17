#include <stdio.h>

void printViaPtr(const int* intPtr)
{
    printf("%d\n", *intPtr);
}

void print2Ints(int i, int j)
{
    printViaPtr(&i);
    printf("%p\n", &i);
    printViaPtr(&j);
}

int main(void)
{
    print2Ints(11, -93);
}
