#include <stdio.h>

void smoothData(int n, double data[]);


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
    double data[] = {1.0, 2.0, 4.0, 4.0};
    smoothData(4, data);
    printf("Smoothed data: %.3lf", data[0]);
    for (int i = 1; i < 4; i++) {
        printf(", %.3lf", data[i]);
    }
    puts("");
}
