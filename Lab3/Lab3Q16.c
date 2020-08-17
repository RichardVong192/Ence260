#include <stdio.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 80

// Read a name (or any string) into the parameter array.
// Terminate it with null.
void readName(int maxLen, char name[])
{
    int c = 0;
    int i = 0;

    printf("Enter your name: ");
    while ((c = getchar()) != '\n' && c != EOF && i < maxLen - 1) {
        name[i++] = c;
    }
    name[i] = '\0';  /* terminator */
}

void convertStringToUpper(char testString[])
{
    int i = 0;
    while (testString[i] != '\0') {
        testString[i] = toupper(testString[i]);
        i++;
    }
}

int main(void)
{
    //readName(MAX_NAME_LENGTH, name);
    char testString[] = "aB0X?";
    convertStringToUpper(testString);
    printf("%s\n", testString);
}

