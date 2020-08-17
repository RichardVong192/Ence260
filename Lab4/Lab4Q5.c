#include <stdio.h>

int uninitialisedArray[10];
int initialisedArray[] = {100, 200, 300};
int globalNum = 20;
int main()
{
    //int data[10];
    //int n = 30;
    char c;
    const char* name = "Angus";
    // Do things
    printf("%s\n", name);
    printf("%p\n", &c);
    printf("%p\n", &globalNum);
    //printf("%p\n", &unitialisedArray);

}
