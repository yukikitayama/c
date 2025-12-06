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

int main()
{
    // test();
    // challenge1();
    challenge2();
    return 0;
}