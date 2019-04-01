// Diff Array and Pointer
// Compile with "-std=c99"
#include <stdio.h>

int main(void)
{
    // Initial array
    int numbers[5] = {1,2,3,4,5};
    int i = 0;

    // Using array export numbers
    for(i = 0; i < 5; i++ )
    {
    int value = numbers[i];
    printf("numbers[%d] = %d\n",i,value);
    }

    // Using pointer and offset export numbers
    for (int i = 0; i < 5; i++ )
    {
    int value = *(numbers + i);
    printf("pointer&index numbers[%d] - %d\n",i,value);
    }

    // Using a pointer export numbers
    int *ptr = numbers;
    for (int i = 0; i < 5; i++ )
    {
    int value = *ptr++;
    printf("%d, *ptr++ = %d\n",i,value);
    }
    return 0;
}
