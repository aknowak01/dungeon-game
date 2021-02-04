#include "../headers.h"
#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
Atributes setPlayerAtributesAuto(int);
Atributes setPlayerAtributesManually(int);
PlayerStats setPlayerStats(PlayerStats,Difficulty);
void printStats(PlayerStats);
void printAtributes(Atributes);
#endif
