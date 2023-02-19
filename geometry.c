#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int find_numbers(char* arr, int i)
{
    int n = 0;
    int c = 0;
    int t = 0;
    double masi;
    double mas[i];
    char nums[10];
    for (int j = 0; j < 10; j++) {
        nums[j] = 'x';
    }
    for (int j = 0; j < strlen(arr); j++) {
        if ((arr[j] >= 48 && arr[j] <= 57) || arr[j] == 46) {
            nums[t] = arr[j];
            t++;
        } else {
            c = 1;
        }
        if (c == 1) {
            if (nums[0] != 'x') {
                masi = atof(nums);
                mas[n] = masi;
                n++;
                for (int j = 0; j < 10; j++) {
                    nums[j] = 'x';
                }
                t = 0;
                c = 0;
            } else {
                c = 0;
            }
        }
    }
    if (mas[i - 1] == 0.0) {
        if (mas[i - 1] == mas[0]) {
            return 0;
        }
        return 1;
    }
    return 0;
}

void remove_numbers(char* text)
{
    int i, j;
    char* str = text;
    for (i = j = 0; text[i] != '\0'; i++) {
        if ((text[i] >= '0' && text[i] <= '9')
            || (text[i] >= 'a' && text[i] <= 'z')
            || (text[i] >= 'A' && text[i] <= 'Z')) {
        } else {
            str[j++] = text[i];
        }
    }
    str[j] = '\0';
}

void remove_spaces(char* text)
{
    int i, j;
    char* str = text;
    for (i = j = 0; text[i] != '\0'; i++) {
        if (text[i] != ' ') {
            str[j++] = text[i];
        }
    }
    str[j] = '\0';
}

void remove_dot(char* text)
{
    int i, j;
    char* str = text;
    for (i = j = 0; text[i] != '\0'; i++) {
        if (text[i] != '.') {
            str[j++] = text[i];
        }
    }
    str[j] = '\0';
}

int Error_check(char* text)
{
    char ustr[80];
    char str[80];
    char* istr;
    char circle[] = "circle";
    char triangle[] = "triangle";
    char polygon[] = "polygon";
    char sep[10] = "( ,)";
    strcpy(ustr, text);
    strcpy(str, text);
    remove_spaces(str);
    remove_numbers(str);
    remove_dot(str);
    istr = strtok(ustr, sep);
    if (strcmp(istr, circle) == 0) {
        int i = 3;
        find_numbers(text, i);
        if (strncmp(&str[0], "(", 1) == 0) {
            if (strncmp(&str[1], ",", 1) == 0) {
                if (strncmp(&str[2], ")", 1) == 0) {
                    if (str[3] == '\0' || str[3] == '\n') {
                        return 0;
                    }
                } else {
                    printf("(15)Expected ')'");
                    return 1;
                }
            } else {
                printf("(11)Expected ','");
                return 1;
            }
        } else {
            printf("(6)Expected '('");
            return 1;
        }
    } else if (strcmp(istr, triangle) == 0) {
        return 0;
    } else if (strcmp(istr, polygon) == 0) {
        return 0;
    } else {
        printf("(1)Expected cirle, triangele or polygon");
        return 1;
    }
    return 1;
}

int main()
{
    FILE* open;
    char text[80];
    if ((open = fopen("text.txt", "r")) == NULL) {
        printf("can't open the file");
        return 1;
    }
    while (fgets(text, 80, open) != NULL) {
        if (Error_check(text) == 0) {
            printf("%s", text);
        } else {
            printf("\nError\n");
        }
    }
    return 0;
}