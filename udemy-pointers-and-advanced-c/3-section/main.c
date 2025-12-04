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

void test3() {
    int num = 30;
    int *p;
    printf("%d\n", num);  // 30
    p = &num;
    printf("%p\n", &num);
    printf("%p\n", p);  // Same address as prev
    *p = 20;
    printf("%d\n", num);  // 20
}

void test4() {
    int num;
    printf("size of int = %d\n", sizeof(num));
    double grade = 99.8;
    printf("size of int = %d\n", sizeof(grade));
}

void test5() {
    int grade = 80;
    printf("size of variable = %d\n", sizeof(grade));  // 4
    double grade_d = 79.9;
    printf("size of variable = %d\n", sizeof(grade_d));  // 8
    int grade1 = 80, grade2 = 90;
    printf("size of variable = %d\n", sizeof(grade1 + grade2));  // 4
    printf("size of variable = %d\n", sizeof(grade1) + sizeof(grade2));  // 8
    printf("size = %d\n", sizeof(double));  // 8
    printf("size = %d\n", sizeof(char));  // 1
    printf("size = %d\n", sizeof(int));  // 4
    printf("size = %d\n", sizeof(float));  // 4

    printf("size = %d\n", sizeof('a'));  // 4
    char c = 'a';
    printf("size = %d\n", sizeof(c));  // 1
    printf("size = %d\n", sizeof("a"));  // 2
}

void test6() {
    int arr[3];
    printf("Array size: %d\n", sizeof(arr));  // 12 = 4 * 3
    double brr[5];
    printf("Array size: %d\n", sizeof(brr));  // 8 * 5 = 40
}

void test7() {
    double brr[5] = {1.3, 3.5, 2.4, 9.9, 7.2};
    printf("Array Size: %d\n", sizeof(brr));  // 8 bytes * 5 = 40 bytes
    int *ptr1;
    int grade1 = 80;
    ptr1 = &grade1;
    printf("%d\n", sizeof(grade1));
    printf("%d\n", sizeof(ptr1));  // 8 bytes, 64-bit environment
    double *ptr2;
    double grade2 = 75.5;
    ptr2 = &grade2;
    printf("%d\n", sizeof(grade2));
    printf("%d\n", sizeof(ptr2));  // 8 bytes
    
    int arr[6];
    printf("Address: %p\n", arr);
    printf("Array size: %d\n", sizeof(arr));
    int *aPtr = arr;
    printf("Address: %p\n", aPtr);
    printf("Array size: %d\n", sizeof(aPtr));
}

int main() {
    // test1();
    // test2();
    // test3();
    // test4();
    // test5();
    // test6();
    test7();
    return 0;
}