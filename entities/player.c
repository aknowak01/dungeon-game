#include "player.h"
struct atrilist
{
    int strength;
    int wisdom;
    int agility;
    int health;
    int mana;
} atri;
struct playerstats
{
    float damage;
    float criticalDamage;
    float magicDamage;
    float criticalChance;
    float dodgeChance;
    float health;
    float manapoints;
} player;
void autoatri(int points)
{
    int tmp=points;
    atri.strength=points-(tmp*0.8);
    atri.wisdom=points-(tmp*0.8);
    atri.agility=points-(tmp*0.8);
    atri.health=points-(tmp*0.8);
    atri.mana=points-(tmp*0.8);
    viewatri();
}
void playeratri(int points)
{
    printf("\n 1.Sila : ");
    scanf("%d",&atri.strength);
    points=points-atri.strength;
    printf("\n Zosta³o ci %d punktow.\n ",points);
    printf("\n 2.Madrosc : ");
    scanf("%d",&atri.wisdom);
    points=points-atri.wisdom;
    printf("\n Zosta³o ci %d punktow.\n ",points);
    printf("\n 3.Zrecznosc : ");
    scanf("%d",&atri.agility);
    points=points-atri.agility;
    printf("\n Zosta³o ci %d punktow.\n ",points);
    printf("\n 4.Zdrowie : ");
    scanf("%d",&atri.health);
    points=points-atri.health;
    printf("\n Zosta³o ci %d punktow.\n ",points);
    printf("\n 5.Magia : ");
    scanf("%d",&atri.mana);
    points=points-atri.mana;
    viewatri();
}
void stats(int dificulty)
{
    if(dificulty==1)
    {
        player.damage=100*1.5*(1+(0.75*atri.strength));
        player.criticalDamage=200+player.damage;
        player.magicDamage=100*(1+(0.80*atri.wisdom));
        player.criticalChance=10+(2*atri.agility);
        player.dodgeChance=15+(2*atri.agility);
        player.health=1000*2*(2*0.5*atri.health);
        player.manapoints=2000*2+(200*0.25*atri.mana);
    }
    else if(dificulty==2)
    {
        player.damage=100*(1+(0.75*atri.strength));
        player.criticalDamage=200+player.damage;
        player.magicDamage=100*(1+(0.80*atri.wisdom));
        player.criticalChance=10+(2*atri.agility);
        player.dodgeChance=15+(2*atri.agility);
        player.health=1000*(2*0.5*atri.health);
        player.manapoints=2000+(200*0.25*atri.mana);
    }
    else if(dificulty==3)
    {
        player.damage=100*1*(1+(0.75*atri.strength));
        player.criticalDamage=200+player.damage;
        player.magicDamage=100*(1+(0.80*atri.wisdom));
        player.criticalChance=10+(2*atri.agility);
        player.dodgeChance=15+(2*atri.agility);
        player.health=1000*0.75*(2*0.5*atri.health);
        player.manapoints=2000*0.75+(200*0.25*atri.mana);
    }
}
void viewstats(char name)
{
    printf(" Twoje Statystyki\n\n");
    printf(" Imie : %c\n",name);
    printf(" Sila : %d,  obrazenia : %.2f i obrazenia krytyczne %.2f\n",atri.strength,player.damage,player.criticalDamage);
    printf(" Zrecznosc : %d,  Szansa na obrazenia krytyczne : %.2f%% i szansa na unik %.2f%%\n",atri.agility,player.criticalChance,player.dodgeChance);
    printf(" Wiedza : %d i obrazenia magiczne : %.2f\n",atri.wisdom,player.magicDamage);
    printf(" Zdrowie : %d i punkty zdrowia : %.2f\n",atri.health,player.health);
    printf(" Magia : %d i punkty magii : %.2f\n\n",atri.mana,player.manapoints);
}
void viewatri()
{
    printf("\n\n Tak zostaly rozdane punkty punkty.\n\n 1.Sila : %d\n 2.Wiedza : %d\n 3.Zrecznosc : %d\n 4.Zdrowie : %d\n 5.Mana : %d\n\n",atri.strength,atri.wisdom,atri.agility,atri.health,atri.mana);
}
