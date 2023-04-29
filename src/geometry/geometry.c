#include <libgeometry/calculator.h>
#include <libgeometry/parser.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE* open;
    int n = 0;
    char* circle = "circle";
    char text[80];
    if ((open = fopen("text.txt", "r")) == NULL) {
        printf("Error: can't open the file");
        return 1;
    }
    while (fgets(text, 80, open) != NULL) {
        n++;
    }
    Circle* circles = malloc(n * sizeof(Circle));
    rewind(open);
    int i = 0;
    while (fgets(text, 80, open) != NULL) {
        if (Error_check(text) == 0) {
            strcpy(circles[i].n, text);
            float* p = find_numbers(text, 3);
            circles[i].point.x = p[0];
            circles[i].point.y = p[1];
            circles[i].radius = p[2];
            circles[i].perimeter = perimeter(circles[i].radius);
            circles[i].area = area(circles[i].radius);
            free(p);
            p = NULL;
        }
        i = i + 1;
    }
    printf("\n");
    for (int i = 0; i < n; i++) {
        if (strstr(circles[i].n, circle)) {
            printf("%d. %s", i + 1, circles[i].n);
            printf("Perimeter = %.2f\n", circles[i].perimeter);
            printf("Area = %.2f\n", circles[i].area);
            printf("Intersects:\n");
            for (int j = 0; j < n; j++) {
                if (i != j && strstr(circles[j].n, circle)) {
                    if (intersect(circles[i], circles[j]) == 1) {
                        printf("%d. circle\n", j + 1);
                    }
                }
            }
            printf("\n");
        }
    }
    free(circles);
    circles = NULL;
    return 0;
}