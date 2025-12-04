#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// void swapInt(int* a, int* b)
// {

// }

// void swapDouble(double* a, double* b)
// {

// }

void genericSwap(void *a, void *b, int size)
{
    // Allocate memory to an address, number of bytes
    void *tempMemory = malloc(size);

    // Memory copy
    memcpy(tempMemory, a, size);
    memcpy(a, b, size);
    memcpy(b, tempMemory, size);

    // Free memory
    free(tempMemory);
}

int main()
{
    int num1 = 5, num2 = 7;
    double average1 = 90.5, average2 = 89.7;

    printf("%f, %f\n", average1, average2);
    genericSwap(&average1, &average2, sizeof(double));
    printf("%f, %f\n", average1, average2);

    printf("%d, %d\n", num1, num2);
    genericSwap(&num1, &num2, sizeof(int));
    printf("%d, %d\n", num1, num2);
    return 0;
}