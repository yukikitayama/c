#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 5

void test1()
{
    int *a;
    int arraySize;
    printf("Enter size of array: ");
    scanf("%d", &arraySize);
    a = (int*)malloc(sizeof(int) * arraySize);

    double *bArr;
    printf("Enter size of array: ");
    scanf("%d", &arraySize);
    bArr = (double*)malloc(sizeof(double) * arraySize);
    if (bArr != NULL)
        printf("Allocation Succeeded!\n");
    else
        printf("Allocation Failed.\n");
}

int *createArray()
{
    int i;
    int *myArr;
    myArr = (int*)malloc(SIZE * sizeof(int));
    if (!myArr)
    {
        printf("You got some error when trying to allocate");
        exit(1);
    }
    printf("Enter %d elements to your array.\n", SIZE);
    for (i = 0; i < SIZE; i++)
    {
        printf("Enter number %d: ", i);
        scanf("%d", &myArr[i]);
    }
    return myArr;
}

void printArr(int *arr, int size)
{
    int i;
    for (i = 0; i < SIZE; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void challenge1()
{
    int* arr;
    arr = createArray();
    printArr(arr, SIZE);
}

void printArray2(int *ptr, int size)
{
    int i;
    printf("Printing the GRADES\n");
    for (i = 0; i < size; i++)
    {
        printf("grades[%d] = %d\n", i, ptr[i]);
    }
    printf("Done\n");
}

void challenge2()
{
    int *grades;
    int arraySize;
    printf("Enter the number of grades that you have: ");
    scanf("%d", &arraySize);
    grades = (int*)malloc(sizeof(int) * arraySize);
    // inputArray
    printArray2(grades, arraySize);
}

void test_realloc()
{
    int i;
    int *grades = NULL;
    int *temp = NULL;
    int totalGrades;
    printf("Enter total grades: ");
    scanf("%d", &totalGrades);
    grades = (int*)malloc(totalGrades * sizeof(int));
    if (grades == NULL)
    {
        printf("Allocating failed...\n");
        return;
    }
    for (i = 0; i < totalGrades; i++)
    {
        printf("Enter grade: ");
        scanf("%d", &grades[i]);
    }
    totalGrades += 2;
    temp = (int*)realloc(grades, totalGrades * sizeof(int));
    if (temp != NULL)
    {
        grades = temp;
    }
    grades[totalGrades - 1] = 100;
    grades[totalGrades - 2] = 90;
    totalGrades -= 3;
    temp = (int*)realloc(grades, totalGrades * sizeof(int));
    if (temp != NULL)
    {
        grades = temp;
    }
    free(grades);
}

void* myRealloc(void* srcblock, unsigned oldsize, unsigned newsize)
{
    int i;
    int smallSize;
    if (oldsize < newsize)
        smallSize = oldsize;
    else
        smallSize = newsize;
    char* resultArr = (char*)malloc(newsize);
    if (!resultArr) return NULL;
    for (i = 0; i < smallSize; i++)
    {
        resultArr[i] = ((char*)srcblock)[i];
    }
    free(srcblock);
    return resultArr;
}

void* myRealloc2(void* srcblock, unsigned oldsize, unsigned newsize)
{
    int smallSize;
    void *newArr = malloc(newsize);
    if (!newArr) return NULL;
    if (oldsize < newsize)
        smallSize = oldsize;
    else
        smallSize = newsize;
    memcpy(newArr, srcblock, smallSize);
}

void test_universal_realloc_function()
{
    int* numbers = (int*)malloc(3 * sizeof(int));
    int* newNumbers = NULL;
    if (!numbers)
        return;
    numbers[0] = 3;
    numbers[1] = 4;
    numbers[2] = 5;
    // newNumbers = (int*)myRealloc(numbers, 3*sizeof(int), 4*sizeof(int));
    // newNumbers = (int*)myRealloc(numbers, 3*sizeof(int), 2*sizeof(int));
    newNumbers = (int*)myRealloc2(numbers, 3*sizeof(int), 2*sizeof(int));
}

int* adjustableReallocation(int* arrSize)
{
    int num, lastIndex = 0, size = 2;
    int* arr = NULL;
    int* temp = NULL;
    printf("Enter num (-1 stops input): ");
    scanf("%d", &num);
    if (num == -1)
    {
        *arrSize - 0;
        return NULL;
    }
    else{
        temp = (int*)malloc(size * sizeof(int));
        if (!temp) return NULL;
        arr = temp;
    }
    while (num != -1)
    {
        if (lastIndex == size)
        {
            size *= 2;
            temp = (int*)realloc(arr, size * sizeof(int));
            if (!temp) return NULL;
            arr = temp;
        }
        arr[lastIndex] = num;
        lastIndex++;
        printf("Enter num (-1 stops input): ");
        scanf("%d", &num);
    }
    arr = (int*)realloc(arr, lastIndex * sizeof(int));
    *arrSize = lastIndex;
    return arr;
}

void test_adjustable_reallocation()
{
    int* arr;
    int arrSize;
    arr = adjustableReallocation(&arrSize);
    printArray2(arr, arrSize);
    printf("Array size: %d", arrSize);
}

int main()
{
    // test1();
    // challenge1();
    // challenge2();
    // test_realloc();
    // test_universal_realloc_function();
    test_adjustable_reallocation();
    return 0;
}