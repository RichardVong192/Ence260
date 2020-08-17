// A test program for the "findTwoLargest" function

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void findTwoLargest(const int data[], int n, int* largest, int* secondLargest)
{
    double max = -INFINITY;
    double secondMax = -INFINITY;

    for (int i = 0; i < n; i++) {
        if (data[i] > max) {
            secondMax = max;
            max = data[i];
        } else if (data[i] < max && data[i] > secondMax) {
            secondMax = data[i];
        } else if (data[i] == max) {
            secondMax = data[i];
        }
    }
    *largest = max;
    *secondLargest = secondMax;
}

int main(void)
{

    int data[] = {5, 4};
    int result1 = 0, result2 = 0;
    findTwoLargest(data, 2, &result1, &result2);
    printf("%d %d\n", result1, result2);
    printf("%d %d\n", data[0], data[1]);
}
