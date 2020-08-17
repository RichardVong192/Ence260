/*Write a program that uses a while loop to read integers from standard
 * input, printing each one on a line by itself, until the number 42
 * has been printed. At that point the program should quit. You may
 * assume that only integers separated by white space will appear
 * in the input and that the number 42 will appear somewhere.
 * [Hint: read the numbers with scanf and a format specifier of just
 * "%d". Each call to scanf will get you the next number from standard
 * input; you don't need to worry about things like line breaks, extra
 * white space, etc.]

Important: you are required to use a while loop and you must not use for or break.
 */

#include <stdio.h>

int main(void)
{

    int n = 0;
    while (n != 42) {
        scanf("%d", &n);
        printf("%d\n",n);
    }
}
