#include <ctest.h>
#include <libgeometry/calculator.h>
#include <libgeometry/parser.h>
#include <math.h>
#include <stdio.h>

#define _USE_MATH_DEFINES

CTEST(INPUT_FILE, CHECK_CIRCLE_AREA)
{
    Circle circle = {.radius = 2};
    float result = area(circle.radius);
    float expected = 12.56;
    ASSERT_DBL_NEAR_TOL(expected, result, 0.01);
}