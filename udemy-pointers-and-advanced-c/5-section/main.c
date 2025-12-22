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
    *average = (num1 + num2) / 2.0;
}

void challenge3_1()
{
    int a, b;
    float average;
    printf("Enter the value for variable 'a': ");
    scanf("%d", &a);
    printf("Enter the value for variable 'b': ");
    scanf("%d", &b);

    updateAverage(a, b, &average);

    printf("%f\n", average);
}

int hasNeighbors(int *arr, int size)
{
    int i;
    for (i = 1; i < size - 1; i++)
    {
        if (arr[i] == arr[i - 1] + arr[i + 1])
            return 1;
    }
    return 0;
}

void challenge4()
{
    int nums1[] = {1, 4, 7, 3, 2};
    int nums2[] = {1, 4, 1, 4, 2};
    printf("%d\n", hasNeighbors(nums1, 5));
    printf("%d\n", hasNeighbors(nums2, 5));
}

int checkIsSorted(int *arr, int size, int *isReallySorted)
{
    int i;
    *isReallySorted = 1;
    for (i = 1; i < size; i++)
    {
        if (arr[i] <= arr[i - 1])
            *isReallySorted = 0;
        if (arr[i] < arr[i - 1])
            return 0;
    }
    return 1;
}

int checkIsSortedRecursive(int *arr, int size, int *isReallySorted)
{
    int result;
    if (size == 1)
    {
        *isReallySorted = 1;
        return 1;
    }
    result = checkIsSortedRecursive(arr, size - 1, isReallySorted);
    if (result != 0 && arr[size - 1] == arr[size - 2])
    {
        *isReallySorted = 0;
    }
    if (result != 0 && arr[size - 1] < arr[size - 2])
    {
        *isReallySorted = 0;
        return 0;
    }
    return result;
}

void challenge5()
{
    // int valuesArr[] = {1, 2, 5, 7, 10};
    // int valuesArr[] = {1, 2, 2, 5, 10};
    int valuesArr[] = {1, 2, 5, 3, 10};
    int isReallySortedFlag;
    int result;

    result = checkIsSorted(valuesArr, 5, &isReallySortedFlag);

    printf("%d, %d\n", result, isReallySortedFlag);

    if (result == 1)
        printf("The array is Really sorted or sorted\n");
    else if (result == 0) 
        printf("The array is not sorted at all\n");
    
    if (isReallySortedFlag == 1)
        printf("The array is Really sorted\n");
    else if (isReallySortedFlag == 0)
        printf("The array is Not Really sorted\n");
}

void swap(char *ptr1, char *ptr2)
{
    char temp;
    temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

void printArray(char* arr, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%c ", arr[i]);
    }
    printf("\n");
}

void reverseArrIterative(char* arr, int size)
{
    int i;
    for (i = 0; i < size / 2; i++)
        swap(&arr[i], &arr[size - 1 - i]);
}

void reverseArrRecursive(char* arr, int size)
{
    if (size > 1)
    {
        swap(&arr[0], &arr[size - 1]);
        reverseArrRecursive(arr + 1, size - 2);
    }
    
}

void challenge6()
{
    char arr[SIZE] = {'a', 'f', 'k', 'd'};
    printArray(arr, SIZE);
    reverseArrRecursive(arr, SIZE);
    printArray(arr, SIZE);
}

void printValuesFrequency(int *arr, int size)
{
    int i, j;
    int leftFlag;
    int countValue;

    for (i = 0; i < size; i++)
    {
        countValue = 1;
        leftFlag = 0;
        
        // Left part
        for (j = 0; j < i; j++)
        {
            if (arr[j] == arr[i])
            {
                leftFlag = 1;
                break;
            }
        }

        if (leftFlag == 1)
        {
            continue;
        }

        // Right part
        for (j = i + 1; j < size; j++)
        {
            if (arr[j] == arr[i])
                countValue++;
        }

        // Print
        printf("%d appears %d times\n", arr[i], countValue);
    }
}

void challenge7()
{
    int arr[] = {5, 6, 7, 6, 5};
    printValuesFrequency(arr, 5);
}

int findSecondSmallest(int *arr, int size)
{
    int i;
    int min1 = arr[0];
    int min2 = arr[0];
    for (i = 1; i < size; i++)
    {
        if (arr[i] < min1)
        {
            min2 = min1;
            min1 = arr[i];
        }
        else if (arr[i] < min2)
        {
            min2 = arr[i];
        }
    }
    return min2;
}

void challenge8()
{
    int arr1[] = {5, 8, 7, 4, 9};
    int min1 = findSecondSmallest(arr1, 5);
    printf("%d\n", min1);
}

int findIf2ElementsSum(int *arr, int size, int value, int *iPtr, int *jPtr)
{
    int i, j;
    for (i = 0; i < size; i++)
    {
        for (j = i + 1; j < size; j++)
        {
            if (arr[i] + arr[j] == value)
            {
                *iPtr = i;
                *jPtr = j;
                return 1;
            }
        }
    }
    *iPtr = 0;
    *jPtr = 0;
    return 0;
}

int findIf2ElementsSumOptimized(int *arr, int size, int value, int *iPtr, int *jPtr)
{
    int i, j;
    int currentSum;
    i = 0;
    j = size - 1;
    while (i < j)
    {
        currentSum = arr[i] + arr[j];
        if (currentSum == value)
        {
            *iPtr = i;
            *jPtr = j;
            return 1;
        }
        else if (currentSum < value)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    *iPtr = 0;
    *jPtr = 0;
    return 0;
}

void challenge9()
{
    int arr[] = {1, 3, 4, 7, 9, 10, 12};
    int i, j;
    int result;
    result = findIf2ElementsSum(arr, 7, 13, &i, &j);
    printf("%d, %d, %d\n", result, i, j);
    result = findIf2ElementsSumOptimized(arr, 7, 14, &i, &j);
    printf("%d, %d, %d\n", result, i, j);
}

int *createArray()
{
    int i;
    int myArr[SIZE];
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

void attention()
{
    int *arr;
    arr = createArray();
    printArr(arr, SIZE);
}

int main()
{
    // test();
    // challenge1();
    // challenge2();
    // test2();
    // challenge3();
    // challenge3_1();
    // challenge4();
    // challenge5();
    // challenge6();
    // challenge7();
    // challenge8();
    // challenge9();
    attention();
    return 0;
}