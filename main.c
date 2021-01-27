#include <stdio.h>
#include <stdlib.h>
#define clrscr() printf("\e[1;1H\e[2J")
#include "GameService.h"

void runGame();

void main() {


    runGame();
}

void runGame() {
    GameState gameState;
    int selectedOption = getOption();
    clrscr();
    if (selectedOption == 1) {
        gameState.difficulty = getDifficulty();
        clrscr();
        gameState.playerName = getPlayerName();
        gameState.playerStats.playerAttributes = getPlayerAttributes(gameState.difficulty);
        printf("\n\n Tak zostaly rozdane punkty punkty.\n\n "
               "1.Sila : %d\n "
               "2.Wiedza : %d\n "
               "3.Zrecznosc : %d\n "
               "4.Zdrowie : %d\n "
               "5.Mana : %d\n\n",
               gameState.playerStats.playerAttributes.strength,
               gameState.playerStats.playerAttributes.wisdom,
               gameState.playerStats.playerAttributes.agility,
               gameState.playerStats.playerAttributes.health,
               gameState.playerStats.playerAttributes.mana);

        gameState.playerStats.playerSkills = getPlayerSkills(gameState.playerStats.playerAttributes,
                                                             gameState.difficulty);

        viewStats(gameState);

        int battleStatus = startBattle(gameState);
        if (battleStatus == 1) { printf("\nWygrana!\n"); }
        else if (battleStatus == 0) { printf("\nPorazka\n"); }
        system("PAUSE");
    }
}
