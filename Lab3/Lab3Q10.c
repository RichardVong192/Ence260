#include <stdio.h>
#include <ctype.h>

#define N_MAX 26

int main(void)
{
    char counts[N_MAX] = { 0 };
    int c = 0;
    int n = 0;
    int i = 0;

    while ((c = getchar()) != EOF) {
        if (isalpha(c)) {
            n = toupper(c) - 65;
            counts[n] += 1;
        }
    }
    for (i = 0; i <= 25; i++) {
        printf("%c: %d\n", (i + 65), counts[i]);
    }
}
