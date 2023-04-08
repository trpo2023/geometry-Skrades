#include <libgeometry/finder.h>
#include <math.h>

double perimeter(double radius)
{
    double perimeter = 2 * 3.14 * radius;
    return perimeter;
}

double area(double radius)
{
    double area = 3.14 * pow(radius, 2);
    return area;
}