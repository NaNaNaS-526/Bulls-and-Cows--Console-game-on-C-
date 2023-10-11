#include "gamelogic.h"
#include "utils.h"
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

void StartGame()
{
    printf("You're playing the game \"Bulls and Cows\"\n");
    printf("Choose the length of the secret number: ");
    int numberLength = 1;
    scanf_s("%d", &numberLength);
    int secretNumber = 0;
    int secretNumberArray[] = malloc(numberLength * sizeof(int));
    secretNumber = GenerateSecretNumber(numberLength);
    RequestNumber(numberLength, secretNumberArray);
}

int GenerateSecretNumber(int numberLength)
{
    bool isNumberCorrect = false;
    int secretNumber = 0;
    int* secretNumberArray = malloc(numberLength * sizeof(int));
    while (!isNumberCorrect)
    {
        int numbers[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        int length = sizeof(numbers) / sizeof(numbers[0]);
        ShuffleArray(numbers, length);
        for (int i = 0; i < numberLength; i++)
        {
            secretNumberArray[i] = numbers[i];
        }
        if (secretNumberArray[0] != 0)
        {
            isNumberCorrect = true;
        }
    }

    ConvertArrayToNumber(secretNumberArray, &secretNumber);

    //printf("Random number: %d\n", generatedNumber);
    return secretNumber;
}

void RequestNumber(int numberLength, int* secretNumberArray)
{
    int movesAmount = 0;
    bool isWin = false;

    int currentNumber;

    while (!isWin)
    {
        currentNumber = GetValidNumberFromUser(numberLength);

        if (CheckForMatches(currentNumber, numberLength, secretNumberArray, movesAmount)) return;
    }
}

int GetValidNumberFromUser(int numberLength)
{
    int currentNumber;
    int currentNumberArray[] = malloc(numberLength * sizeof(int));
    while (true)
    {
        printf("Enter the four-digit number with no duplicate digits: ");
        if (!CheckForNumber(numberLength, currentNumber)) continue;

        ConvertNumberToArray(currentNumber, currentNumberArray);

        bool noDublicates = true;

        for (int i = 0; i < numberLength; i++)
        {
            for (int j = 0; j < numberLength; j++)
            {
                if ((currentNumberArray[i] == currentNumberArray[j]) & (i != j))
                {
                    noDublicates = false;
                    break;
                }
                noDublicates = true;
                continue;
            }
            if (!noDublicates) break;
        }

        if (noDublicates) return currentNumber;
    }
}

bool CheckForNumber(int numberLength, int currentNumber)
{
    if (scanf_s("%d", &currentNumber) != 1)
    {
        while (getchar() != '\n');
        return false;
    }
    if (currentNumber / (int)pow(10, numberLength - 1) <= 0 | currentNumber / (int)pow(10, numberLength - 1) >= 10)
    {
        return false;
    }
    return true;
}

bool CheckForMatches(int currentNumber, int numberLength, int* secretNumberArray, int movesAmount)
{
    
    movesAmount++;
    int bulls = 0;
    int cows = 0;
    for (int i = 0; i < numberLength; i++)
    {
        for (int j = 0; j < numberLength; j++)
        {
            if ((i == j) & (secretNumberArray[i] == currentNumberArray[j]))
            {
                bulls++;
                continue;
            }
            else if (secretNumberArray[i] == currentNumberArray[j])
            {
                cows++;
                continue;
            }
        }
    }
    if (bulls == numberLength)
    {
        Win(currentNumber, movesAmount);
        return true;
    }
    printf("--------------------\n\tBulls: %d, Cows: %d\n--------------------\n", bulls, cows);
    return false;
}

bool Win(int number, int movesAmount)
{
    printf("--------------------\nWIN!!!!!!!!!!!\n--------------------\nNumber of moves: %d\n--------------------", movesAmount);
    return true;
}










