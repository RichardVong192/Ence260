/*Write a program that loops, reading characters from standard input and
 * writing their decimal values to standard output one per line, until EOF occurs.
 */

#include <stdio.h>
int main(void)
{
    int c = 0;

    //printf("Enter a line: ");
    while ((c = getchar()) != EOF) {
        printf("%d\n", c);
    }
}
