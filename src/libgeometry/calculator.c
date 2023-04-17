#include <libgeometry/calculator.h>
#define _USE_MATH_DEFINES
#include <math.h>

double perimeter(double radius)
{
    double perimeter = 2 * M_PI * radius;
    return perimeter;
}

double area(double radius)
{
    double area = M_PI * pow(radius, 2);
    return area;
}