#include <stdio.h>
#include <stdlib.h>

void swap(int *ptr1, int *ptr2) {
    int temp;
    temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

int main() {
    // int num1, num2;
    // printf("Enter num1: ");
    // scanf("%d", &num1);
    // printf("Enter num2: ");
    // scanf("%d", &num2);
    // printf("BEFORE SWAP: num1 - %d, num2 - %d\n", num1, num2);
    // swap(&num1, &num2);
    // printf("AFTER SWAP: num1 - %d, num2 - %d\n", num1, num2);

    int a = 10;
    void *ptr = &a;
    printf("%d\n", *(int*)ptr);

    return 0;
}