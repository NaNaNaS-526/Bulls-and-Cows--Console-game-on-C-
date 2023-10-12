#include "gamelogic.h"
#include "utils.h"
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

void StartGame()
{
	printf("You're playing the game \"Bulls and Cows\"!\n");
	printf("Choose the length of the secret number: ");

	int secretNumberLength = 0;
	scanf_s("%d", &secretNumberLength);

	printf("Choose the maximum number of moves: ");

	int numberOfMoves = 0;
	scanf_s("%d", &numberOfMoves);

	int secretNumber = GenerateSecretNumber(secretNumberLength);
	GetNumberFromUser(secretNumber, secretNumberLength, numberOfMoves);
}

int GenerateSecretNumber(int secretNumberLength)
{
	int numbers[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int numbersSize = sizeof(numbers) / sizeof(numbers[0]);

	srand(time(NULL));
	for(int i = 0; i < numbersSize; i++)
	{
		int randomNumber = rand() % (sizeof(numbers) / sizeof(numbers[0]));
		SwapArrayElements(&numbers[i], &numbers[randomNumber]);
	}

	if (numbers[0] == 0)
	{
		SwapArrayElements(&numbers[0], &numbers[1]);
	}

	int secretNumber = 0;
	for (int i = 0; i < secretNumberLength; i++)
	{
		secretNumber = secretNumber * 10 + numbers[i];
	}
	printf("%d\n", secretNumber);
	return secretNumber;
}

void GetNumberFromUser(int secretNumber, int secretNumberLength, int numberOfMoves)
{
	int userNumber = 0;
	int currentNumberOfMoves = 0;
	while(currentNumberOfMoves < numberOfMoves)
	{
		currentNumberOfMoves++;
		bool isUserNumberCorrect = false;
		while (!isUserNumberCorrect)
		{
			printf("Enter the %d-digit number: ", secretNumberLength);

			if (scanf_s("%d", &userNumber) != 1)
			{
				printf("Invalid input. Please enter a number.\n");
				while (getchar() != '\n');
				continue;
			}
			if(HasDuplicateDigits(userNumber)) continue;

			int userNumberLength = userNumber == 0 ? 1 : log10(abs(userNumber)) + 1;
			if (userNumberLength != secretNumberLength) continue;
			else isUserNumberCorrect = true;
		}
		
		if (CheckUserNumberForBullsAndCows(userNumber, secretNumber, secretNumberLength))
		{
			printf("YOU WIN!!!!!!!!!\nNumber of moves: %d", currentNumberOfMoves);
			return;
		}
		if (currentNumberOfMoves >= numberOfMoves)
		{
			printf("YOU LOSE!!!!!!!!");
			return;
		}
	}
}

bool CheckUserNumberForBullsAndCows(int userNumber, int secretNumber, int secretNumberLength)
{
	int bulls = 0;
	int cows = 0;
	for (int i = 0; i < secretNumberLength; i++)
	{
		int secretDigit = (int)(secretNumber / pow(10, i)) % 10;
        for (int j = 0; j < secretNumberLength; j++)
        {
            int userDigit = (int)(userNumber / pow(10, j)) % 10;
            if (secretDigit == userDigit)
            {
                if (i == j) bulls++;
                else cows++;
            }
        }
	}
	printf("\t\tBulls: %d | Cows: %d\n", bulls, cows);
	if (bulls == 4) return true;
	return false;
}