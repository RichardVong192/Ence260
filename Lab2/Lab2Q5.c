/*Write a program that uses scanf to read a single integer from standard
 * input and prints 'Odd' if the integer is odd,  'Even' if it's a
 * non-zero even number, or 'Zero' if it's zero. You may assume that
 * the program will be tested only with valid numeric input.
 */

#include <stdio.h>

int main(void)
{
    int n = 0;
    scanf("%d", &n);
    if (n == 0) {
        printf("Zero");
    } else if (n % 2 == 0 ) {
        printf("Even");
    } else {
        printf("Odd");
    }
}
