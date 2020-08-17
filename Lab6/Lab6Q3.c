#include <stdio.h>
#include <stdlib.h>

int* ramp(int n)
{
    int* num = malloc(n * sizeof(int));
    int count = 1;

    for (int i = 0; i < n; i++) {
        num[i] = count + i;
    }
    return num;
}

int main(void)
{
    int* data = ramp(5);
    for (int i = 0; i < 5; i++) {
        printf("%d ", data[i]);
    }
    free(data);
}
