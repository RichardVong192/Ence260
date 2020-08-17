#include <stdio.h>
#include <stdlib.h>



typedef struct vector2d_s Vector2d;

struct vector2d_s {
    int x;
    int y;
};

Vector2d vector(int x, int y)
{
    Vector2d tuple = {x, y};
    return tuple;
}

Vector2d vectorSum(Vector2d v1, Vector2d v2)
{
    Vector2d result = {v1.x + v2.x, v1.y + v2.y};
    return result;
}


int main(void)
{
    Vector2d v1 = vector(100, -97);
    Vector2d v2 = vector(11, 1);
    Vector2d v3 = vectorSum(v1, v2);
    printf("(%d, %d) + (%d, %d) = (%d, %d)\n", v1.x, v1.y, v2.x, v2.y, v3.x, v3.y);
}
