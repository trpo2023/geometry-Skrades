#include <libgeometry/calculator.h>
#define _USE_MATH_DEFINES
#include <math.h>

float perimeter(float radius)
{
    double perimeter = 2 * M_PI * radius;
    return perimeter;
}

float area(float radius)
{
    float area = M_PI * pow(radius, 2);
    return area;
}

int intersect(Circle circle1, Circle circle2)
{
    int f = 0;
    float rsum = circle1.radius + circle2.radius;
    float dx = circle2.point.x - circle1.point.x;
    float dy = circle2.point.y - circle1.point.y;
    if ((dx * dx + dy * dy) <= (rsum * rsum)) {
        f = 1;
    }
    return f;
}