#include <stdio.h>
#include <stdbool.h>

int myIndex(int data[], int* element)
{
    int* startptr = &data[0];
    return (element - startptr);
}

int main(void)
{
    int data[30];
    int* p = &data[17];
    printf("Index is %d\n", myIndex(data, p));
}
