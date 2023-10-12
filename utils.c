#include "utils.h"
#include <stdbool.h>

void SwapArrayElements(int* firstElement, int* secondElement)
{
	int temporaryElement = *firstElement;
	*firstElement = *secondElement;
	*secondElement = temporaryElement;
}

bool HasDuplicateDigits(int number) 
{
    bool digits[10] = { false };
    while (number > 0) {
        int digit = number % 10;
        if (digits[digit]) return true;
        digits[digit] = true;
        number /= 10;
    }
    return false;
}
