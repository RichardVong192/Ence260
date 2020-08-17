/*
 * A program which reads input data, by the function readDoubles, smooths the data
 * using the function smoothData, then prints the times when the smooth data
 * exceeds the definded critical value, plus the peak recorded acceleration and
 * the time at which it occured.
 *
 * Author: Richard Vong
 * Date: 05/08/19
 */


#include <stdio.h>

#define CRITICAL_HIGH 9.81
#define CRITICAL_LOW 5.0
#define N_MAX 100000

int readDoubles(int n, double data[]);
void smoothData(int n, double data[]);

/*
 * Function that reads a sequence of type double numbers from standard
 * input into an array until the maximum number is read of EOF occurs.
 * Function returns the number of values to be read.
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


/* Function to smooth the nth element in a array of data in place by
 * replacing each input value with a value obtained from a weighted average
 * of it and its two neighbours, using weights of 1:2:1 .
 */
void smoothData(int n, double data[])
{
    int i = 0;
    double var_initial;
    double var_last;
    double var_i = 0;
    double var_temp = 0;
    double var_Second_to_last = data[n-2];

    for (i = 0; i <= (n - 1); i++) {
        if (i == 0) {
            var_initial = (3.0 * data[0] + data[1]) / 4.0;
        } else if (i == (n - 1)) {
            var_last = (var_Second_to_last + 3.0 * data[n-1]) / 4.0;
            data[i] = var_last;
            data[0] = var_initial;
        } else {
            var_i = (data[i-1] + 2 * data[i] + data[i + 1])/ 4.0;
            data[i-1] = var_temp;
            var_temp = var_i;
            if (i == n - 2) {
                data[i] = var_i;
            }
        }
    }
}

int main(void)
{
    double data[N_MAX] = {0.0};
    int numRead = 0;
    double max = 0;
    double Maximum_accel_timestamp = 0;
    double crit_timestamp = 0;
    double flag = 0;

    numRead = readDoubles(1000000, data);
    smoothData(numRead, data);

    for (int i = 1; i < numRead; i++) {
        if (data[i] < CRITICAL_LOW) {
            flag = 1;
        }
        if (flag == 1 && data[i] > CRITICAL_HIGH) {
            crit_timestamp = i / 100.0;
            printf("Acceleration of 9.81 m/sec^2 exceeded at t = %.2lf secs.\n", crit_timestamp);
            flag = 0;
        }
    }
    for (int i = 0; i < numRead; i++) {
        if (data[i] > max) {
            max = data[i];
            Maximum_accel_timestamp = i / 100.0;
        }
    }
    printf("\nMaximum acceleration: %0.2lf m/sec^2 at t = %.2lf secs.", max, Maximum_accel_timestamp);
}






