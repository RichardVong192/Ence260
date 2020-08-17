/*
 * Write a program that reads a single integer n from standard input
 *  (without a prompt) and then prints to standard output the squares of
 *  the integers from 1 up to n (inclusive), one per line. Use a for loop.
 *  You may not use while, do or break.
 */

#include <stdio.h>

int main(void)
{
    int n = 0;
    int i = 1;
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        printf("%d\n", i * i);
    }
}
