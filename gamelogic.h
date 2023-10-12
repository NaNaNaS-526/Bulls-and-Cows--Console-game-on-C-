#ifndef GAMELOGIC_H
#define GAMELOGIC_H	

#include <stdbool.h>

void StartGame();
int GenerateSecretNumber(int secretNumberLength);
void GetNumberFromUser(int secretNumber, int secretNumberLength, int numberOfMoves);
bool CheckUserNumberForBullsAndCows(int userNumber, int secretNumber, int secretNumberLength);

#endif
