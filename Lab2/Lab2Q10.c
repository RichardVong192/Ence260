#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int i = 0;
    bool done = false;
    for (i = 0; !done; i++) {
        if (i == 10){
            done = true;
        }
    }

    int i = 0;
    while (!done) {
        if (i == 10) {
            done = true;
        }
        i++;
    }

    printf("%d\n", i);
}

