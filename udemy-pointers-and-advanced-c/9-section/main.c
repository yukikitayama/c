#include <stdio.h>
#include <stdlib.h>

void test_array_of_pointers()
{
    int *arr[5];
    int i;
    for (i = 0; i < 5; i++)
    {
        arr[i] = (int *)calloc(3, sizeof(int));
    }
    arr[1][1] = 30;
    printf("Enter value: ");
    scanf("%d", &arr[0][2]);
    printf("Arr[4][2] = %d\n", arr[4][2]);
    printf("Arr[1][1] = %d\n", arr[1][1]);
    printf("Arr[0][2] = %d\n", arr[0][2]);
}

void test_2d_array_different_sizes()
{
    int *arr[5];
    int i;
    int numOfColumns;
    for (i = 0; i < 5; i++)
    {
        printf("Enter number of columns: ");
        scanf("%d", &numOfColumns);
        arr[i] = (int *)calloc(numOfColumns, sizeof(int));
    }
}

void test_2d_array_different_sizes2()
{
    int **a;
    int rows, columns;
    int i;
    printf("Please enter number of rows: ");
    scanf("%d", &rows);

    a = (int **)calloc(rows, sizeof(int *));
    for (i = 0; i < rows; i++)
    {
        printf("Enter number of columns: ");
        scanf("%d", &columns);
        a[i] = (int *)calloc(columns, sizeof(int));
    }
}

int **allocate2DMatrix()
{
    int **a;
    int rows, columns;
    int i;
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    a = (int **)calloc(rows, sizeof(int *));
    if (!a)
        return NULL;
    for (i = 0; i < rows; i++)
    {
        printf("Number of columns for row %d", i + 1);
        scanf("%d", &columns);
        a[i] = (int *)calloc(columns, sizeof(int));
        if (!a[i])
        {
            // free matrix
            return NULL;
        }
    }
    return a;
}

int **allocate2DMatrix2d(int rows, int columns)
{
    int **a;
    int i;
    a = (int **)calloc(rows, sizeof(int *));
    if (!a)
        return NULL;
    for (i = 0; i < rows; i++)
    {
        a[i] = (int *)calloc(columns, sizeof(int));
        if (!a[i])
        {
            // free matrix
            return NULL;
        }
    }
    return a;
}

void test_allocate_2d_matrix()
{
    int **myMatrix;
    myMatrix = allocate2DMatrix();

    int rows, columns;
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Number of columns for row: ");
    scanf("%d", &columns);
}

void print2DDynamicMatrix(int **a, int rows, int columns)
{
    int i, j; // i: row, j: col
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < columns; j++)
        {
            printf("%10d ", a[i][j]);
        }
        printf("\n");
    }
}

void test_print_2d_matrix()
{
    printf("Test");
}

void freeMatrix(int **a, int rows)
{
    int i;
    for (i = 0; i < rows; i++)
    {
        free(a[i]);
    }
    free(a);
}

void swapRows(void **a, int row1, int row2)
{
    void *temp;
    temp = a[row1];
    a[row1] = a[row2];
    a[row2] = temp;
}

void swapColumns(int **a, int column1, int column2, int totalRows)
{
    int i;
    int temp;
    for (i = 0; i < totalRows; i++)
    {
        temp = a[i][column1];
        a[i][column1] = a[i][column2];
        a[i][column2] = temp;
    }
}

int **createLowerTriangular(int n)
{
    int **a;
    int i;
    a = (int**)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
    {
        a[i] = (int*)malloc((i + 1) * sizeof(int));
    }
    return a;
}

int **createUpperTriangular(int n)
{
    int **a;
    int i;
    a = (int**)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
    {
        a[i] = (int*)malloc((n - i) * sizeof(int));
    }
    return a;
}



int main()
{
    // test_array_of_pointers();
    // test_allocate_2d_matrix();
    // test_print_2d_matrix();

    return 0;
}