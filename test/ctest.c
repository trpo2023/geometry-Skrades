#include <ctest.h>
#include <libgeometry/calculator.h>
#include <libgeometry/parser.h>
#include <math.h>
#include <stdio.h>

#define _USE_MATH_DEFINES

CTEST(Calculation, Check_circle_area)
{
    Circle circle = {.radius = 2};
    float result = area(circle.radius);
    float expected = M_PI * pow(circle.radius, 2);
    ASSERT_DBL_NEAR(expected, result);
}

CTEST(Calculation, Check_circle_perimeter)
{
    Circle circle = {.radius = 2};
    float result = perimeter(circle.radius);
    float expected = 2 * M_PI * circle.radius;
    ASSERT_DBL_NEAR(expected, result);
}

CTEST(Calculation, Check_circle_intersection)
{
    Circle circle1 = {.point = {.x = 1.0, .y = 1.0}, .radius = 1};
    Circle circle2 = {.point = {.x = 2.0, .y = 2.0}, .radius = 3.5};
    Circle circle3 = {.point = {.x = 5.0, .y = 2.0}, .radius = 3};
    float result1 = intersect(circle1, circle2);
    int expected1 = 1;
    ASSERT_EQUAL(expected1, result1);
    float result2 = intersect(circle1, circle3);
    int expected2 = 0;
    ASSERT_EQUAL(expected2, result2);
}