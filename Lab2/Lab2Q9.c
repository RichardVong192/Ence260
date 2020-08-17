/*Write a program that uses a do...while loop (not an ordinary while loop)
 *  to read integers from standard input, printing each one on a line by
 *  itself, until the number 42 has been printed. At that point the program
 *  should quit. You may assume that only integers separated by white space
 *  will appear in the input and that the number 42 will appear somewhere.
 * [Hint: read the numbers with scanf and a format specifier of just "%d".]

* You are not permitted to use a for loop or a basic while loop in this
* program. Nor may you used break anywhere.
 */

#include <stdio.h>

int main(void)
{

    int n = 0;
    do {
        scanf("%d", &n);
        printf("%d\n",n);
    } while (n != 42);
}
