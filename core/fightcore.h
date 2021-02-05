#include "../headers.h"
#ifndef FIGHTCORE_H_INCLUDED
#define FIGHTCORE_H_INCLUDED
Enemy setMobDamage(int dificulty,Enemy mob);
int startFight(GameSettings gameSettings);
int getFightOptions();
int getBattleStatus(int battleResult);
#endif // FIGHTCORE_H_INCLUDED
