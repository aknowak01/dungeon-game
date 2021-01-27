#include "randomevents.h"
#include <stdio.h>
#include <stdlib.h>
struct atrilist{
    short int strength;
    short int wisdom;
    short int agility;
    short int health;
    short int mana;
}atri;
struct playerstats{
    float damage;
    float criticalDamage;
    float magicDamage;
    float criticalChance;
    float dodgeChance;
    float health;
    float manapoints;
}player;
void autoatri(int points){
    int tmp=points;
    atri.strength=points-(tmp*0.8);
    atri.wisdom=points-(tmp*0.8);
    atri.agility=points-(tmp*0.8);
    atri.health=points-(tmp*0.8);
    atri.mana=points-(tmp*0.8);
    viewatri();
}
void playeratri(int points){
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
void stats(int dificulty){
    if(dificulty==1){
    player.damage=100*1.5*(1+(0.75*atri.strength));
    player.criticalDamage=200+player.damage;
    player.magicDamage=100*(1+(0.80*atri.wisdom));
    player.criticalChance=10+(2*atri.agility);
    player.dodgeChance=15+(2*atri.agility);
    player.health=1000*2*(2*0.5*atri.health);
    player.manapoints=2000*2+(200*0.25*atri.mana);}
    else if(dificulty==2){
    player.damage=100*(1+(0.75*atri.strength));
    player.criticalDamage=200+player.damage;
    player.magicDamage=100*(1+(0.80*atri.wisdom));
    player.criticalChance=10+(2*atri.agility);
    player.dodgeChance=15+(2*atri.agility);
    player.health=1000*(2*0.5*atri.health);
    player.manapoints=2000+(200*0.25*atri.mana);}
    else if(dificulty==3){
    player.damage=100*0.75*(1+(0.75*atri.strength));
    player.criticalDamage=200+player.damage;
    player.magicDamage=100*(1+(0.80*atri.wisdom));
    player.criticalChance=10+(2*atri.agility);
    player.dodgeChance=15+(2*atri.agility);
    player.health=1000*0.75*(2*0.5*atri.health);
    player.manapoints=2000*0.75+(200*0.25*atri.mana);}
}
struct enemytype1{
    float health;
    float damage;
}skeleton,zombie;
void enemytype1damage(int dificulty){
    srand(time(0));
    if(dificulty==1){skeleton.damage=(rand()%400)+200;zombie.damage=(rand()%300)+100;}
    else if(dificulty==2){skeleton.damage=(rand()%600)+400;zombie.damage=(rand()%450)+200;}
    else if(dificulty==3){skeleton.damage=(rand()%800)+600;zombie.damage=(rand()%650)+300;}
}
void enemytype1health(){
    skeleton.health=4000;
    zombie.health=6000;
}
int fight1(int dificulty)
{
    int enemy=0,option,goaway,move;
    srand(time(0));
    enemytype1damage(dificulty);
    enemytype1health();
    if(enemy==0)
    {
        while(1)
        {
            printf(" Walczysz z Szkieletem.\n Zdrowie Szkieleta : %f\n Twoje zdrowie : %f\n\n 1.Atak.\n 2.Atak magiczny.\n 3.Próba ucieczki. 4.Unik i atak.\n\n Wybierz opcje :  ",skeleton.health,player.health);
            scanf("%d",&option);
            if(skeleton.health-player.damage>0){
                if(option==1){
                skeleton.health=skeleton.health-player.damage;
                player.health=player.health-skeleton.damage;
                }
                else if(option==2){
                skeleton.health=skeleton.health-player.magicDamage;
                player.health=player.health-skeleton.damage;
                }
                else if(option==3){
                   goaway=rand()%10;
                   if(goaway==1||goaway==9)
                   {
                       return 2;
                   }
                   else player.health=player.health-skeleton.damage;
                }
                else if(option==4){
                    move=rand()%100-player.dodgeChance;
                }

            }

            else return 1;


        }

    }

}
void viewstats(char name){
    printf(" Twoje Statystyki\n\n");
    printf(" Imie : %c\n",name);
    printf(" Sila : %d,  obrazenia : %.2f i obrazenia krytyczne %.2f\n",atri.strength,player.damage,player.criticalDamage);
    printf(" Zrecznosc : %d,  Szansa na obrazenia krytyczne : %.2f%% i szansa na unik %.2f%%\n",atri.agility,player.criticalChance,player.dodgeChance);
    printf(" Wiedza : %d i obrazenia magiczne : %.2f\n",atri.wisdom,player.magicDamage);
    printf(" Zdrowie : %d i punkty zdrowia : %.2f\n",atri.health,player.health);
    printf(" Magia : %d i punkty magii : %.2f\n\n",atri.mana,player.manapoints);
}
void viewatri(){
    printf("\n\n Tak zostaly rozdane punkty punkty.\n\n 1.Sila : %d\n 2.Wiedza : %d\n 3.Zrecznosc : %d\n 4.Zdrowie : %d\n 5.Mana : %d\n\n",atri.strength,atri.wisdom,atri.agility,atri.health,atri.mana);
}
void game(){
    int option1,points,dificulty,temp,battle;
    char name;
    printf(" Wybierz Poziom trudnoœci.\n\n 1. Latwy\n 2. Sredni\n 3. Trudny\n 4. Informacje o poziomach trudnoœci\n\n Wybierz jedna z opcji : ");
    scanf("%d",&dificulty);
    printf("\n");
    while(1){
        if(dificulty==1){
            points=40;
            break;}
        else if(dificulty==2){
            points=30;
            break;}
        else if(dificulty==3){
            points=20;
            break;}
        else if(dificulty==4){
            printf(" Poziom trudnosci okresla ilosc atrybutow oraz przeliczniki punktow zdrowia i many, oraz zadawane obrazenia.\n Na latwym poziomie otrzymujesz 50 punktow atrybutow, 2x punktow zdrowia i many,oraz 1.5x obrazen.\n Na srednim poziomie otrzymujesz 30 punktow atrybutow, 1x punktow zdrowia i many,oraz 1x obrazen\n Na trudny poziomie otrzymujesz 15 punktow atrybutow, 0.75x punktow zdrowia i many,oraz 0.75x obrazen\n\n Wybierz poziom trudnosci : ");
            scanf("%d",&dificulty);
            continue;}
        else {printf("Wybierz jeszcze raz : ");scanf("%d",&dificulty);continue;}
    }
    temp=dificulty;
    printf("\n\n");
    printf(" Podaj swoje imie : ");
    scanf("%s",&name);
    printf("\n");
    printf(" Tworzenie postaci. \n\n 1. Wlasna postac.\n 2. Gotowa Postac (Uwaga atrybuty przydzielone po rowno).\n\n Wybierz opcje : ");
    scanf("%d",&option1);
    printf("\n");
    if(option1==1){
        printf(" Masz %d punktów atrybutów.\n\n Rozdawaj je madrze gdyz nie mo¿esz wrocic do zadnego z nich aby zmienic! \n\n",points);// Zak³adam, ¿e osoba graj¹ca umie przydzieliæ punkty i nie wyjdzie poza zakres
        playeratri(points);}
    else if(option1==2){
        autoatri(points);
    }
    stats(temp);
    viewstats(name);
    battle=fight1(temp);
    if(battle==1){printf("\nWygrana!\n");}
    else if(battle=0){printf("\nPorazka\n");}
    system ("PAUSE");
}
