#include <stdio.h>

double average(double a, double b)
{
    return (a + b) / 2;
}

int main(void){
    printf("Average of 10 and 20 is %.3lf\n", average(10, 20));
}
