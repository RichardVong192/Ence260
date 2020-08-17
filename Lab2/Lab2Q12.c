/* Herbert the Hellalump question
 */

#include <stdio.h>

int main(void)
{

    double screeHeight = 0;
    double rushHeight = 0;
    double slideBack = 0;
    int attempts = 0;
    double currentHeight = 0;

    scanf("%lf %lf %lf", &screeHeight, &rushHeight, &slideBack);

    while (currentHeight < screeHeight) {
        attempts++;
        currentHeight += rushHeight;
        if (currentHeight < screeHeight) {
            currentHeight -= slideBack;
        }
    }
    printf("%d", attempts);


}
