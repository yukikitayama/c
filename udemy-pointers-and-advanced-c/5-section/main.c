#include <stdio.h>

#define SIZE 4

int findIfKeyInArray(int *arr, int size, int key)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (arr[i] == key)
            return 1;
    }
    return 0;
}

void test()
{
    int grades[SIZE] = { 80, 85, 72, 90 };
    int result;
    result = findIfKeyInArray(grades, SIZE, 81);
    printf("%d\n", result);
}

int findMaxInArray(int *arr, int size)
{
    int maxSoFar;
    int i;
    
    if (size <= 0)
        return -1;
    
    maxSoFar = arr[0];
    for (i = 1; i < size; i++)
    {
        if (arr[i] > maxSoFar)
            maxSoFar = arr[i];
    }
    return maxSoFar;
}

void challenge1()
{
    int grades[SIZE] = { 80, 85, 72, 90 };
    int maxGrade;
    maxGrade = findMaxInArray(grades, SIZE);
    printf("%d\n", maxGrade);
}

int findSumArray(int *arr, int size)
{
    int i, sum = 0;
    for (i = 0; i < size; i++)
        sum += arr[i];
    return sum;
}

double findArrayAverage(int* arr, int size)
{
    int sumOfArray;
    sumOfArray = findSumArray(arr, size);
    return (double)sumOfArray / size;
}

void challenge2()
{
    int grades[SIZE] = { 80, 85, 72, 90 };
    double average;
    average = findArrayAverage(grades, SIZE);
    printf("%f\n", average);
}

void inputArray(int* arr, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("Enter value #%d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

void displayArray(int *arr, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("Value #%d: %d\n", i + 1, arr[i]);
    }
}

void test2()
{
    int grades[SIZE];
    inputArray(grades, SIZE);
    displayArray(grades, SIZE);
}

void minMax(int *pArr, int size, int *minValue, int *maxValue)
{
    int i;
    *minValue = pArr[0];
    *maxValue = pArr[0];
    for (i = 1; i < size; i++)
    {
        if (pArr[i] < *minValue)
            *minValue = pArr[i];
        if (pArr[i] > *maxValue)
            *maxValue = pArr[i];
    }
}

void challenge3()
{
    int myGrades[] = {80, 90, 100};
    int min, max;
    minMax(myGrades, 3, &min, &max);

    printf("The max value in your grades: %d\n", max);
    printf("The min value in your grades: %d\n", min);
}

void updateAverage(int num1, int num2, float *average)
{
    
}

void challenge3_1()
{
    int a, b;
    float average;
    printf("Enter the value for variable 'a': ");
    scanf("%d", &a);
    printf("Enter the value for variable 'b': ");
    scanf("%d", &b);

    updateAverage();

    printf();
}

int main()
{
    // test();
    // challenge1();
    // challenge2();
    // test2();
    // challenge3();
    challenge3_1();
    return 0;
}