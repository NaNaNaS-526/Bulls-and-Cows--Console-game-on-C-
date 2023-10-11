#ifndef GAMELOGIC_H
#define GAMELOGIC_H	

#include <stdbool.h>

void StartGame();
int GenerateSecretNumber();
void RequestNumber();
int GetValidNumberFromUser();
bool CheckForMatches(int number);
bool Win(int number);

#endif
