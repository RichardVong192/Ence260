/*Write a program that loops, reading characters from standard input until EOF occurs.
 *  For each character read, a single line of output should be printed as follows:

If the character is a new-line character (which has the value '\012', i.e. 10 decimal),
*  the printed line should be '\n' (including the quotes). Otherwise ...
The character itself should be printed, enclosed in single quotes followed by a colon
* and a space, followed by either:
Digit <n> if the character represents one of the digits 0 through 9,
*  where <n> is the represented digit, or
Letter <n> if the character is one of the letters 'a' through 'z' or
* 'A' through 'Z', in which case <n> is the ordinal value of the letter,
*  i.e. 1 for 'a' or 'A', 2 for 'b' or 'B' etc, or
Non-alphanumeric if the character is neither a digit nor a letter
 */

#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int c = 0;

    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            printf("'\\n'\n");
        } else if (isdigit(c)) {
            printf("'%c': Digit %c\n", c, c);
        } else if (isalpha(c)) {
            if (isupper(c)) {
                printf("'%c': Letter %d\n", c, toupper(c) - 64);
            } else {
                printf("'%c': Letter %d\n", c, c - 96);
            }
        } else {
            printf("'%c': Non-alphanumeric\n", c);
        }
    }
}
