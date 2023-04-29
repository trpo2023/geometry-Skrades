#pragma once

typedef struct {
    float x;
    float y;
} Point;

typedef struct {
    Point point;
    float radius;
    float perimeter;
    float area;
    char n[80];
} Circle;

float perimeter(float radius);

float area(float radius);

int intersect(Circle cirlce1, Circle circle2);