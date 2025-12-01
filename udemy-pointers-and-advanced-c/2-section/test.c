#include <stdio.h>
#include <stdlib.h>

void test1() {
    int a = 5;
    int *p;
    printf("%d\n", a);
    printf("%p\n", &a);
    p = &a;
    printf("%p\n", p);
    printf("%d\n", *p);  // Dereferencing
}

void test2() {
    int grade1=80, grade2=100;
    printf("Grade1 VALUE = %d\n", grade1);
    printf("Grade1 ADDRESS = %p\n", &grade1);
    printf("Grade2 VALUE = %d\n", grade2);
    printf("Grade2 ADDRESS = %p\n", &grade2);

}

void test3() {
    /*
    5, 7
    5, 7
    6, 10
    6, 10
    10, 10
    10, 7
    */
}

void findMinMax(int num1, int num2, int *pMax, int *pMin) {
    if (num1 > num2) {
        *pMin = num2;
        *pMax = num1;
    } else {
        *pMin = num1;
        *pMax = num2;
    }
}

int main() {
    // test1();
    // test2();
    int a = 5, b = 7;
    int max, min;
    findMinMax(a, b, &max, &min);
    printf("max between %d and %d = %d\n", a, b, max);
    printf("min between %d and %d = %d\n", a, b, min);
    return 0;
}