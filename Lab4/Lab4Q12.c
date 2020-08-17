#include <stdio.h>
#include <stdbool.h>

char data[100];

bool isInData(char* p)
{
    if ((p >= &data[0]) && (p <= &data[99])) {
        return 1;
    } else {
        return 0;
    }
}

int main(void)
{
    // Test with a hidden global thing1
    printf("%d\n", isInData(&thing1));
}
