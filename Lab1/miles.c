#include <stdio.h>

#define SCALE_FACTOR 1.609344

int main(void)
{
    float miles = 0;
    float kilometers = 0;
    printf("How many miles? ");
    scanf("%f", &miles);
    kilometers = (miles * SCALE_FACTOR);
    printf("That's %.2f km.\n",kilometers);
}
