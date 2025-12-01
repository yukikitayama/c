#include <stdio.h>
#include <stdlib.h>

void test1() {
    int *ptr;
    int grades[3] = {80, 90, 100};
    printf("grades start at %p\n", grades);
    printf("grades: %d\n", *grades);
    printf("address: %p\n", &grades[0]);
    printf("address: %p\n", &grades[1]);
    printf("address: %p\n", &grades[2]);
    printf("grades start at %p\n", grades);
    printf("grades start at %p\n", grades + 1);
}

void test2() {
    int grades[3] = {80, 90, 100};
    int *gradesPtr = grades;
    printf("grades start at: %p\n", gradesPtr);
    printf("grades start at: %p\n", gradesPtr + 1);

    double grades2[3] = {80.5, 90.3, 99.9};
    printf("grades start at: %p\n", grades2);
    printf("grades start at: %p\n", grades2 + 1);
    printf("grades start at: %p\n", grades2 + 2);
}

int main() {
    // test1();
    test2();
    return 0;
}