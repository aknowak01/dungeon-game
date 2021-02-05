#include"fightcore.h"
#define TRUE 1
#define FALSE 0
Enemy setMobDamage(int dificulty,Enemy mob)
{
    srand(time(0));
    if(dificulty==1)
    {
        if(mob.type==1)
        {
            mob.damage=(rand()%400)+200;
        }

        if(mob.type==2)
        {
            mob.damage=(rand()%300)+100;
        }
    }
    else if(dificulty==2)
    {
        if(mob.type==1)
        {
            mob.damage=(rand()%600)+400;
        }

        if(mob.type==2)
        {
            mob.damage=(rand()%450)+200;
        }
    }
    else if(dificulty==3)
    {
        if(mob.type==1)
        {
            mob.damage=(rand()%800)+600;
        }

        if(mob.type==2)
        {
            mob.damage=(rand()%650)+300;
        }
    }
    return mob;
}

int startFight(GameSettings gameSettings)
{
    PlayerStats playerStats=gameSettings.playerstats;
    Difficulty difficulty=gameSettings.difficulty;
    Atributes atributes=playerStats.playerAtributes;

    int enemyId,option,goaway,attackchance;
    float move;
    srand(time(0));

    Enemy zombie;
    zombie.type=1;
    zombie.health=6000;
    Enemy skeleton;
    zombie.type=0;
    skeleton.health=4000;

    zombie=setMobDamage(difficulty.difficultyLevel,zombie);
    skeleton=setMobDamage(difficulty.difficultyLevel,skeleton);
    enemyId=rand()%2;
    if(enemyId==0)
    {
        printf(" Walczysz z Szkieletem.\n");
        while(1)
        {
            printf(" Zdrowie Szkieleta : %.2f\n Twoje zdrowie : %.2f\n\n 1.Atak.\n 2.Atak magiczny.\n 3.PrÛba ucieczki. 4.Unik i atak.\n\n Wybierz opcje :  ",skeleton.health,playerStats.health);
            scanf("%d",&option);
            if(skeleton.health-playerStats.damage>100||skeleton.health-playerStats.magicDamage>0)
            {
                if(playerStats.health-skeleton.damage<100)
                {
                    return 3;
                }
                else if(option==1)
                {
                    skeleton.health-=playerStats.damage;
                    playerStats.health-=skeleton.damage;
                }
                else if(option==2)
                {
                    skeleton.health-=playerStats.magicDamage;
                    playerStats.health-=skeleton.damage;
                }
                else if(option==3)
                {
                    goaway=rand()%10;
                    if(goaway==1||goaway==9)
                    {
                        return 2;
                    }
                    else playerStats.health-=skeleton.damage;
                }
                else if(option==4)
                {
                    move=rand()%100-playerStats.dodgeChance;
                    if(move>40)
                    {
                        skeleton.health-=playerStats.damage;
                    }
                    else
                    {
                        skeleton.health-=playerStats.damage;
                        playerStats.health-=skeleton.damage;
                    }
                }
            }
            else return 1;
        }
    }
    else if(enemyId==1)
    {
        printf(" Walczysz z Zombie.\n");
        while(1)
        {
            printf(" Zdrowie Zombie : %.2f\n Twoje zdrowie : %.2f\n\n 1.Atak.\n 2.Atak magiczny.\n 3.PrÛba ucieczki.\n 4.Unik i atak.\n\n Wybierz opcje :  ",zombie.health,playerStats.health);
            scanf("%d",&option);
            if(zombie.health-playerStats.damage>100)
            {
                if(playerStats.health-zombie.damage<100)
                {
                    return 3;
                }
                else if(option==1)
                {
                    zombie.health-=playerStats.damage;
                    playerStats.health-=zombie.damage;
                }
                else if(option==2)
                {
                    zombie.health-=playerStats.magicDamage;
                    playerStats.health-=zombie.damage;
                }
                else if(option==3)
                {
                    goaway=rand()%10;
                    if(goaway==1||goaway==9)
                    {
                        return 2;
                    }
                    else playerStats.health-=zombie.damage;
                }
                else if(option==4)
                {
                    move=rand()%100-playerStats.dodgeChance;

                    if(move>40)
                    {
                        zombie.health-=playerStats.damage;
                    }
                    else
                    {
                        zombie.health-=playerStats.damage;
                        playerStats.health-=zombie.damage;
                    }
                }
            }
            else return 1;
        }
    }
}

int getFightOptions()
{
    int fightOption;
    printf(" Zblizasz sie do drzwi, na twojej drodze stoi przeciwnik.\n\n"
           " Wybierz dzialanie.\n\n"
           " 1.Zaatakuj przeciwnika.\n"
           " 2.Sprawdü czy jest inne przejscie.\n"
           "\n\n Wybierz Opcje: ");
    scanf("%d",&fightOption);
    return fightOption;
}

int getBattleStatus(int battleResult)
{
    if(battleResult==1)
    {
        printf("\nWygrana!\n");
        return TRUE;
    }
    else if(battleResult=3)
    {
        printf("\nPorazka\n");
        return FALSE;
    }
    else if(battleResult=2)
    {
        printf("\nUdalo ci sie uciec\n");
        return TRUE;
    }
    return FALSE;
}
