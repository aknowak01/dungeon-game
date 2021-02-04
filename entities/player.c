#include "../headers.h"
Atributes setPlayerAtributesAuto(int maxPoints)
{
    Atributes selectedAtributes;

    selectedAtributes.strength=maxPoints-(maxPoints*0.8);
    selectedAtributes.wisdom=maxPoints-(maxPoints*0.8);
    selectedAtributes.agility=maxPoints-(maxPoints*0.8);
    selectedAtributes.health=maxPoints-(maxPoints*0.8);
    selectedAtributes.mana=maxPoints-(maxPoints*0.8);

    return selectedAtributes;
}
Atributes setPlayerAtributesManually(int maxPoints)
{
    Atributes selectedAtributes;
    int remainingPoints=maxPoints;

    printf("\n 1.Sila : ");
    scanf("%d",&selectedAtributes.strength);
    remainingPoints-=selectedAtributes.strength;
    printf("\n Zosta³o ci %d punktow.\n ",remainingPoints);
    printf("\n 2.Madrosc : ");
    scanf("%d",&selectedAtributes.wisdom);
    remainingPoints-=selectedAtributes.wisdom;
    printf("\n Zosta³o ci %d punktow.\n ",remainingPoints);
    printf("\n 3.Zrecznosc : ");
    scanf("%d",&selectedAtributes.agility);
    remainingPoints-=selectedAtributes.agility;
    printf("\n Zosta³o ci %d punktow.\n ",remainingPoints);
    printf("\n 4.Zdrowie : ");
    scanf("%d",&selectedAtributes.health);
    remainingPoints-=selectedAtributes.health;
    printf("\n Zosta³o ci %d punktow.\n ",remainingPoints);
    printf("\n 5.Magia : ");
    scanf("%d",&selectedAtributes.mana);
    remainingPoints-=selectedAtributes.mana;

    return selectedAtributes;
}
PlayerStats setPlayerStats(PlayerStats playerStats,Difficulty difficulty)
{
    playerStats.damage=100*difficulty.damageValue*(1+(0.75*playerStats.playerAtributes.strength));
    playerStats.criticalDamage=200+playerStats.damage;
    playerStats.magicDamage=100*(1+(0.80*playerStats.playerAtributes.wisdom));
    playerStats.criticalChance=10+(2*playerStats.playerAtributes.agility);
    playerStats.dodgeChance=15+(2*playerStats.playerAtributes.agility);
    playerStats.health=1000*difficulty.healthValue*(2*0.5*playerStats.playerAtributes.health);
    playerStats.manapoints=2000*difficulty.manaValue+(200*0.25*playerStats.playerAtributes.mana);
    return playerStats;
}
void printStats(PlayerStats playerStats)
{
    printf(" Twoje Statystyki\n\n");
    printf(" Imie : %s\n",playerStats.playerName);
    printf(" Sila : %d,  obrazenia : %.2f i obrazenia krytyczne %.2f\n",playerStats.playerAtributes.strength,playerStats.damage,playerStats.criticalDamage);
    printf(" Zrecznosc : %d,  Szansa na obrazenia krytyczne : %.2f%% i szansa na unik %.2f%%\n",playerStats.playerAtributes.agility,playerStats.criticalChance,playerStats.dodgeChance);
    printf(" Wiedza : %d i obrazenia magiczne : %.2f\n",playerStats.playerAtributes.wisdom,playerStats.magicDamage);
    printf(" Zdrowie : %d i punkty zdrowia : %.2f\n",playerStats.playerAtributes.health,playerStats.health);
    printf(" Magia : %d i punkty magii : %.2f\n\n",playerStats.playerAtributes.mana,playerStats.manapoints);
}
void printAtributes(Atributes atributes)
{
    printf("\n\n Tak zostaly rozdane punkty punkty.\n\n 1.Sila : %d\n 2.Wiedza : %d\n 3.Zrecznosc : %d\n 4.Zdrowie : %d\n 5.Mana : %d\n\n",atributes.strength,atributes.wisdom,atributes.agility,atributes.health,atributes.mana);
}
