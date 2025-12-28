#include <stdio.h>
#include <stdlib.h>

void test_array_of_pointers()
{
    int* arr[5];
    int i;
    for (i = 0; i < 5; i++)
    {
        arr[i] = (int*)calloc(3, sizeof(int));
    }
    arr[1][1] = 30;
    printf("Enter value: ");
    scanf("%d", &arr[0][2]);
    printf("Arr[4][2] = %d\n", arr[4][2]);
    printf("Arr[1][1] = %d\n", arr[1][1]);
    printf("Arr[0][2] = %d\n", arr[0][2]);
}

int main()
{
    test_array_of_pointers();
    return 0;
}