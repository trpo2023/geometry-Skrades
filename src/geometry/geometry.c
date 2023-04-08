#include <libgeometry/finder.h>
#include <libgeometry/parser.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float x;
    float y;
} Point;

typedef struct {
    Point point;
    double radius;
} Circle;

int main()
{
    FILE* open;
    char text[80];
    if ((open = fopen("text.txt", "r")) == NULL) {
        printf("Error: can't open the file");
        return 1;
    }
    while (fgets(text, 80, open) != NULL) {
        if (Error_check(text) == 0) {
            printf("\n%s", text);
            double* p = find_numbers(text, 3);
            Circle circle = {.point = {.x = p[0], .y = p[1]}, .radius = p[2]};
            // printf("%.2f", circle.point.x);
            printf("Perimeter = %.2f\n", perimeter(circle.radius));
            printf("Area = %.2f\n", area(circle.radius));
            // free(p);
            // p = NULL;
        }
    }
    return 0;
}