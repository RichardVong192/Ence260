/* Write a C program that uses scanf to read two integers n1 and n2,
 * where n1 > 1 and n2 >= n1. The program should then print all the
 * prime numbers between n1 and n2 inclusive.

A simplistic algorithm with nested loops is all that's expected here.
*  The outer loop iterates through all integers in the range n1 to n2
*  inclusive. The inner loop iterates through all the integers from 2
* to n - 1 inclusive, checking if each one is a factor of the current
* number n whose 'primeness' is being assessed. More efficient algorithms
*  exist, however, and you're welcome to try to find one if you wish.
*/
#include <stdio.h>

int main(void)
{

    int n1;
    int n2;
    int i;
    int j;
    int flag = 1;

    scanf("%d %d", &n1, &n2);
    for (i = n1; i <= n2; i++) {
        for (j = 2; j <= i-1; j++) {
            if (i % j == 0) {
                flag = 0;
            }
        }
        if (flag == 1) {
            printf("%d\n", i);
        }
        flag = 1;
    }
}

