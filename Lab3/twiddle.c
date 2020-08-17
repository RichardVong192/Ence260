#include <stdio.h>
#define MAX_NAME_LENGTH 80

char name[MAX_NAME_LENGTH] = {0};

void readName(void)
{
    int c = 0;
    int i = 0;
    printf("Enter your name: ");
    while ((c = getchar()) != '\n' && c != EOF && i < MAX_NAME_LENGTH -1) {
        name[i++] = c;
    }
    name[i] = 0; // name[i] = '\0'; terminator
}

int main(void)
{
    readName();
    printf("%s\n",name);

}
