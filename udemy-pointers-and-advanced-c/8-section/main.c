#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* createNoDuplexArray(int* sourceArray, int size, int* newSize)
{
    int i, j = 0;
    int count = 1;
    int* noDuplexArray;
    for (i = 0; i < size - 1; i++)
    {
        if (sourceArray[i] != sourceArray[i + 1])
        {
            count++;
        }
    }
    noDuplexArray = (int*)malloc(count * sizeof(int));
    *newSize = count;
    for (i = 0; i < size - 1; i++)
    {
        if (sourceArray[i] != sourceArray[i + 1])
        {
            noDuplexArray[j] = sourceArray[i];
            j++;
        }
    }
    noDuplexArray[j] = sourceArray[i];

    // for (j = 0; j < count; j++)
    //     printf("%d ", noDuplexArray[j]);
    // printf("\n");

    return noDuplexArray;
}

void printArray(int* arr, int size)
{
    int i;
    printf("Array values: \n");
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void exercise1()
{
    int* newArray;
    int newArraySize;
    int originalArray[] = {1,3,3,5,6,7,7,7,8,12,12};
    printArray(originalArray, 11);
    newArray = createNoDuplexArray(originalArray, 11, &newArraySize);
    printArray(newArray, newArraySize);
    free(newArray);
}

void generateOddEvenArrays(int* sourceArray, int size)
{
    int i;
    int* oddArray;
    int* evenArray;
    int evenArrayIndex=0, oddArrayIndex=0;
    int oddArraySize=0, evenArraySize=0;
    for (i = 0; i < size; i++)
    {
        if (sourceArray[i] % 2 == 0)
        {
            evenArraySize++;
        }
        else
        {
            oddArraySize++;
        }
    }
    oddArray = (int*)malloc(oddArraySize * sizeof(int));
    evenArray = (int*)malloc(evenArraySize * sizeof(int));
    for (i = 0; i < size; i++)
    {
        if (sourceArray[i] % 2 == 0)
        {
            evenArray[evenArrayIndex] = sourceArray[i];
            evenArrayIndex++;
        }
        else
        {
            oddArray[oddArrayIndex] = sourceArray[i];
            oddArrayIndex++;
        }
    }
    printf("Odd Array Values: \n");
    printArray(oddArray, oddArraySize);
    printf("Even Array Values: \n");
    printArray(evenArray, evenArraySize);
}

void exercise2()
{
    int originalArray[] = {12,5,7,8,3,10,4,9};
    printf("Source/Original array values: \n");
    printArray(originalArray, 8);
    generateOddEvenArrays(originalArray, 8);
}

void* insert(void* arr, unsigned size, unsigned idx, void* source, unsigned sourceSize)
{
    void* newArr = malloc(size + sourceSize);
    if (!newArr) return NULL;
    memcpy(newArr, arr, idx);
    memcpy((char*)newArr + idx, source, sourceSize);
    memcpy((char*)newArr + idx + sourceSize, (char*)arr + idx, size - idx);
    return newArr;
}

void advanced()
{
    int arr[] = {3,4,7};
    int newNum = 5;
    int insertIndex = 1;
    int* newArr = (int*)insert(arr, sizeof(int) * 3, sizeof(int) * 1, &newNum, sizeof(int) * 1);
    printArray(arr, 3);
    printArray(newArr, 4);
}

int main()
{
    // exercise1();
    // exercise2();
    advanced();
    return 0;
}