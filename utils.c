#include "utils.h"

void SwapArrayElements(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void ShuffleArray(int array[], int arrayLength)
{
    srand(time(0));
    for (int i = arrayLength - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        SwapArrayElements(&array[i], &array[j]);
    }
}

void ConvertArrayToNumber(int array[], int* number)
{
    for (int i = 0; i < 4; i++)
    {
        *number += array[i] * pow(10, 3 - i);
    }
    return number;
}
void ConvertNumberToArray(int number, int array[])
{
    for (int i = 0; i < 4; i++)
    {
        array[i] = number % (int)pow(10, 4 - i) / (int)pow(10, 3 - i);
    }
}