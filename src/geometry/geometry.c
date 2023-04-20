#include <libgeometry/calculator.h>
#include <libgeometry/parser.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE* open;
    int n = 0;
    int flag;
    char text[80];
    if ((open = fopen("text.txt", "r")) == NULL) {
        printf("Error: can't open the file");
        return 1;
    }
    while (fgets(text, 80, open) != NULL) {
        flag = Error_check(text);
        if (flag == 0) {
            n++;
        } else {
            break;
        }
    }
    Circle* circles = malloc(n * sizeof(Circle));
    rewind(open);
    int c = 0;
    if (flag == 0) {
        while (fgets(text, 80, open) != NULL) {
            strcpy(circles[c].n, text);
            float* p = find_numbers(text, 3);
            circles[c].point.x = p[0];
            circles[c].point.y = p[1];
            circles[c].radius = p[2];
            circles[c].perimeter = perimeter(circles[c].radius);
            circles[c].area = area(circles[c].radius);
            c = c + 1;
            free(p);
            p = NULL;
        }
        for (int i = 0; i < n; i++) {
            printf("%d. %s", i + 1, circles[i].n);
            printf("Perimeter = %.2f\n", circles[i].perimeter);
            printf("Area = %.2f\n", circles[i].area);
            printf("Intersects:\n");
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    if (intersect(circles[i], circles[j]) == 1) {
                        printf("%d. circle\n", j + 1);
                    }
                }
            }
            printf("\n");
        }
    }
    return 0;
}