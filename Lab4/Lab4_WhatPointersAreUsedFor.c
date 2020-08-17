#include <stdio.h>
#include <ctype.h> // For isdigit

void myscanf(char format[], int* pi)
{
    int c = 0;
    int num = 0;
    while (isdigit((c = getchar()))) {
        num = num * 10 + c - '0';
    }
    *pi = num;
}

int main(void)
{
    int i = 0;
    scanf("%d", &i);
    printf("i = %d\n", i);

}
