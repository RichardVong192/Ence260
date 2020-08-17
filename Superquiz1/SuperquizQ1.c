/*
 * Program that reads a sequence of numbers from standard input into an
 * array until the maximun number is readed or EOF occurs.
 * Author: Richard Vong
 * Date: 04/08/19
 */

#include <stdio.h>

int readDoubles(int n, double data[]);


/*
 * Function that reads a sequence of type double numbers from standard
 * input into an array until the maximum number is read of EOF occurs.
 * Function returns the read values.
 */
int readDoubles(int n, double data[])
{
    double input;
    int i = 0;

    while (((scanf("%lf", &input)) != EOF) && i != n) {
        data[i] = input;
        i++;
    }
    return i;
}

int main(void)
{
    double data[1] = {0.0};
    int numRead = 0;

    numRead = readDoubles(1, data);
    printf("Read %d values:\n", numRead);
    for (int i = 0; i < numRead; i++) {
        printf("%0.3lf\n", data[i]);
    }
}
