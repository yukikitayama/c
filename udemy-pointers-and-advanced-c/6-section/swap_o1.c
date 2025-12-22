#include <stdio.h>
#include <stdlib.h>

void swapArrayO1(void** ptr1, void** ptr2)
{
    void* temp;
    temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

int main()
{
    return 0;
}