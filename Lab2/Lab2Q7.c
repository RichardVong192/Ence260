/*Rewrite the function with just a single statement by using a
 *  conditional expression i.e., by using the "? ... :" ternary operator.
 *  The answer box has been preloaded with the correct form for the
 * function definition - all you have to do is replace the comment
 * with an appropriate one-line statement. Hint: the statement will
 * be a return statement.
 */

#include <stdio.h>

int gringe(int boink, int flunk)
{
    return (boink == flunk) ? 42 : flunk - 11;
}

int main()
{
    printf("%d\n", gringe(23, 23));

    printf("%d\n", gringe(23, 24));


}
