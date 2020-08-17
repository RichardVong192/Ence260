/*Write a C program that reads three white-space separated
 * floating point values a, b and c from standard input and
 * prints the solution to the quadratic equation  ax2+bx+c=0
 */

#include <stdio.h>
#include <math.h>

int main(void)
{
    double a = 0;
    double b = 0;
    double c = 0;
    scanf("%lf %lf %lf", &a, &b, &c);
    double discriminant = b * b - 4 * a * c;
    if (a == 0) {
        printf("Not a quadratic");
    } else if (discriminant < 0) {
        printf("Imaginary roots");
    } else {
        double root1 = (-b - sqrt(discriminant)) / (2 * a);
        double root2 = (-b + sqrt(discriminant)) / (2 * a);
        if (root1 < root2) {
            printf("Roots are %0.4lf and %0.4lf", root1, root2);
        } else {
            printf("Roots are %0.4lf and %0.4lf", root2, root1);
        }
    }
}
