#include "randomevents.h"
#include <stdio.h>
#include <stdlib.h>
#define N 10
#define TRUE 1
#define FALSE 0
#include "entities/player.c"

#include <stdbool.h>


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
            printf(" Zdrowie Szkieleta : %.2f\n Twoje zdrowie : %.2f\n\n 1.Atak.\n 2.Atak magiczny.\n 3.Próba ucieczki. 4.Unik i atak.\n\n Wybierz opcje :  ",skeleton.health,playerStats.health);
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
            printf(" Zdrowie Zombie : %.2f\n Twoje zdrowie : %.2f\n\n 1.Atak.\n 2.Atak magiczny.\n 3.Próba ucieczki.\n 4.Unik i atak.\n\n Wybierz opcje :  ",zombie.health,playerStats.health);
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
int runChapterOne(GameSettings gameSettings)
{
    PlayerStats playerStats=gameSettings.playerstats;
    Difficulty difficulty=gameSettings.difficulty;
    Atributes atributes=playerStats.playerAtributes;
    int fightOption,battleResult,isWinBattle,boss;
    while(1)
    {
        fightOption=getFightOptions();
        if(fightOption==1)
        {
            battleResult=startFight(gameSettings);
            isWinBattle=getBattleStatus(battleResult);
            if(isWinBattle)
            {
                fightOption=getFightOptions();
                if(fightOption=1)
                {
                    printf("Przeciwnik uciekl\n Czy chcesz go gonić?\n 1. Tak \n 2. Nie\n Wybierz Opcje : ");
                    scanf("%d",&fightOption);
                    if(fightOption==1)
                    {
                        battleResult=startFight(gameSettings);
                        isWinBattle=getBattleStatus(battleResult);
                        if(isWinBattle)
                        {
                            printf("Znajdujesz magiczna skrzynie,\n\n 1. Otworzyc.\n\n 2. Nie otwierac\n\n 3. Sprobuj zniszczyc skrzynie\n\n Wybierz opcje : ");
                            scanf("%d",&fightOption);
                            if(fightOption==1||fightOption==3)
                            {
                                printf(" Znajdujesz Ostrze Zniszczonego Krola.\n\n Dostajesz dodatkowe obrazenia.\n\n Wraz z wyciagniecie miecza wyleciala dziwna esencja i zniknela.");
                                //player.damage+=400;
                                printf("\n\n Kiedy przemierzasz nastepny korytarz czujesz jak jakas dziwna energia probuje cie pochlonac.\n\n Wbiegasz do pokoju naprzeciwko.\n\n");
                                return runBossFightOne(gameSettings);
                            }
                            else if (fightOption==2)
                            {
                                if(fightOption!=1)
                                {
                                    printf("Przeciwnik zauważa cie i atakuje\n");
                                }
                                fightOption=getFightOptions();
                                battleResult=startFight(gameSettings);
                                isWinBattle=getBattleStatus(battleResult);
                                printf("Po walce \n");
                                return runBossFightOne(gameSettings);
                            }
                        }
                    }
                }
                else printf("Slepy zaulek");
            }
            else
            {
                printf("\n\n Przegrales, wracasz do menu glownego.\n\n");
                main();
            }
        }

        else if(fightOption==2)
        {
            continue;
        }
        return FALSE;
    }
}
int runBossFightOne(GameSettings gameSettings)
{
    PlayerStats playerStats=gameSettings.playerstats;
    Difficulty difficulty=gameSettings.difficulty;
    Atributes atributes=playerStats.playerAtributes;

    int attack1,fightOption,bosshealth=22000;
    printf("Tajemniczy glos mowi: Ten zamek zamieni sie w twoja trumne.\n\n Wybierz odpowiedz.\n\n 1. Bede walczyc do konca!\n 2.Poddaje sie, oszczedz mnie.\n\n Wybierz opcje : ");
    scanf("%d",&fightOption);
    if(fightOption==1)
    {
        printf("\n\n Mowisz: Bede walczyc do konca, nie przestraszy mnie byle duch! ");
        printf("\n Tajemniczy Glos odpowiada: A wiec walczmy, od kilku set lat sie nie ruszalem, nareszcie nadszedl czas.");
        printf("\n\n Przeciwnik Wylania sie z cienia, okazuje sie ze to dusza Krogga, wlasciciela miecza ktory znalazles.");
        while(1)
        {
            printf("\n\nTwoje zdrowie %f\nZdrowie Krogga %d\n\n Wybierz opcje ataku : \n 1. Zaatakuj mieczem\n 2. Odwroc jego uwage rzucajac wlocznia ktora lezy na ziemi\n 3. Rzuc czar\n\n Wybierz opcje : ",playerStats.health,bosshealth);
            scanf("%d",&attack1);
            if(bosshealth-playerStats.damage>0||bosshealth-playerStats.magicDamage>0)
            {
                if(attack1==1)
                {
                    bosshealth-=playerStats.damage;
                    playerStats.health-=200;
                    continue;
                }
                else if(attack1==2)
                {
                    printf("Przeciwnik śmieje sie i napiera");
                    playerStats.health-=200;
                    continue;
                }
                else if(attack1==3)
                {
                    bosshealth-=playerStats.magicDamage;
                    playerStats.health-=200;
                    continue;
                }
                else if(playerStats.health<200)
                {
                    printf("\n\n Przegrales, wracasz do menu glownego.\n\n");
                    main();
                }
            }
            else
            {
                break;
            }
        }
        printf("Krogg zaczyna się chwiac, ale jego potega wciaz jest wielka, uderza cie w glowe i odpycha krzyczac : To jeszcze nie koniec!!!\n\n");
        return true;
    }
    if(fightOption==2)
    {
        printf("Krogg patrzy z zazenowaniem i wbija ci ostrze w serce. Umierasz.\n\n Wracasz do menu glownego");
        main();
    }
    return FALSE;
}
int runChapterTwo(GameSettings gameSettings)
{
    PlayerStats playerStats=gameSettings.playerstats;
    Difficulty difficulty=gameSettings.difficulty;
    Atributes atributes=playerStats.playerAtributes;

    int fightOption,battleResult,isWinBattle,boss;
    printf("\n Kiedy upadasz widzisz jak duch Krogga leci korytarzem i zawala mur. Musisz znalezc inna droge.\n\n Kiedy dochodzisz do siebie");
    while(1)
    {
        fightOption=getFightOptions();
        if(fightOption==1)
        {
            battleResult=startFight(gameSettings);
            isWinBattle=getBattleStatus(battleResult);
            if(isWinBattle==1)
            {
                fightOption=getFightOptions();
                if(fightOption=1)
                {
                    printf("Przeciwnik uciekl\n Czy chcesz go gonić?\n 1. Tak \n 2. Nie\n Wybierz Opcje : ");
                    scanf("%d",&fightOption);
                    if(fightOption==1)
                    {
                        battleResult=startFight(gameSettings);
                        isWinBattle=getBattleStatus(battleResult);
                        if(isWinBattle==1)
                        {
                            printf("Znajdujesz magiczna skrzynie,\n\n 1. Otworzyc.\n\n 2. Nie otwierac\n\n 3. Sprobuj zniszczyc skrzynie\n\n Wybierz opcje : ");
                            scanf("%d",&fightOption);
                            if(fightOption==1||fightOption==3)
                            {
                                printf(" Widzisz placzaca kobiete, podchodzisz blizej.\n\n Pytasz sie : Kim jestes?.\n\n Odpowiada : Idz glupcze, obudziles tego potwora, teraz znowu bedzie dreczyl swiat\n\n Odpowiadasz : Przepraszam nie mailem tego za cel, przyszedlem tu na prosbe maga z okolicznej wioski, podobno potwory przeszkadzały bardziej niz zwykle. \n\n Duch odpowiada : Wybacz nie powinnam pochopnie cie oceniac. Jestem Lisandra, zona Krogga. Jedynym wyjsciem aby przestal plugawic ten swiat jest zniszczenie go.\n\n Ruszajmy bede ci towarzyszyc.\n\n");
                                printf("\n\n Zblizasz sie do glownych drzwi,.\n\n Lisandra leci za toba.\n\n");
                                return runBossFightTwo(gameSettings);

                            }
                            else if (fightOption==2)
                            {
                                if(fightOption!=1)
                                {
                                    printf("Przeciwnik zauważa cie i atakuje\n");
                                }
                                fightOption=getFightOptions();
                                battleResult=startFight(gameSettings);
                                isWinBattle=getBattleStatus(battleResult);
                                printf("Po walce \n");
                                return runBossFightTwo(gameSettings);
                            }
                        }
                    }
                }
                else printf("Slepy zaulek");
            }
            else
            {
                printf("\n\n Przegrales, wracasz do menu glownego.\n\n");
                main();
            }
        }
    else if(fightOption==2)
    {
        printf("\n Nie ma innej drogi\n\n");
        continue;
    }
    }
    return FALSE;
}
int runBossFightTwo(GameSettings gameSettings)
{
    PlayerStats playerStats=gameSettings.playerstats;
    Difficulty difficulty=gameSettings.difficulty;
    Atributes atributes=playerStats.playerAtributes;

    int attack1,fightOption,bosshealth=35000,zycietamtejpostaci=1;

    printf("Kroczysz ruinami zamku wraz z postacia X. Z oddali slyszysz dziwny halas. Czy chcesz to sprawdzic? 1. Tak, idz w strone tajemnej komanty 2. Nie, idz dalej korytarzem");
    scanf("%d",&fightOption);
    if (fightOption==1)
    {

        printf("W komnacie widzisz tron, a na nim siedzi Krogg tylem do drzwi. Atakujesz go z zaskoczenia, zadajac dodatkowe obrazenia. Krogg smieje sie i mowi ""Odwaznie!"", po czym podejmuje z toba walke.");
        bosshealth-=5000;

    }
    else if (fightOption==2)
    {
        zycietamtejpostaci=0;
        ("Po zrobieniu kilku krokow slyszysz krzyk za soba. To Krogg zabil twojego towarzysza z zaskoczenia i uciekl do sali tronowej! Czy biegniesz za nim? 1. Tak 2. Nie");
        scanf("%d",&fightOption);
        if (fightOption==1)
        {
            printf("To pulapka! Tuz za drzwiami Krogg uderza cie z zaskoczenia, jednak ty podejmujesz walke. ""Czy sadzisz ze mzoesz mnie pokonac?"" smieje sie Krogg podczas walki.");
            playerStats.health-=300;
        }
        if (fightOption==2)
        {
            printf("Po kolejnym zignorowaniu Krogga on atakuje cie z tylu ze zwiekszona sila, umierasz. Wracasz do menu.");
            main();
        }

        if (fightOption==1) //czyli ze jestes w sali tronowej i podjales walke XD bo albo od razu dales 1 i ci idzie na dol, jak dales 2 to potem musisz dac 1 zeby wyladowac w komnacie i walczyc
        {

            while(1)
            {
                printf("\n\nTwoje zdrowie %f\nZdrowie Krogga %d\n\n Wybierz opcje ataku : \n 1. Zaatakuj mieczem\n2. Rzuc czar\n\n Wybierz opcje : ",playerStats.health,bosshealth);

                scanf("%d",&attack1);

                if(bosshealth-playerStats.damage>0||bosshealth-playerStats.magicDamage>0)
                {
                    if(attack1==1)
                    {
                        bosshealth-=playerStats.damage;
                        playerStats.health-=300;
                        if(zycietamtejpostaci==1) bosshealth-=150;
                        continue;
                    }


                    else if(attack1==2)
                    {
                        bosshealth-=playerStats.magicDamage;
                        playerStats.health-=200;
                        if(zycietamtejpostaci==1) bosshealth-=100;
                        continue;
                    }
                }
            }

        }
    }
    return false;
}
int getFightOptions()
{
    int fightOption;
    printf(" Zblizasz sie do drzwi, na twojej drodze stoi przeciwnik.\n\n"
           " Wybierz dzialanie.\n\n"
           " 1.Zaatakuj przeciwnika.\n"
           " 2.Sprawdź czy jest inne przejscie.\n"
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
void game()
{
    GameSettings gameSettings;
    PlayerStats selectedPlayerStats;

    int fightOption,difficulty,battleResult;
    printf(" Wybierz Poziom trudnoœci.\n\n 1. Latwy\n 2. Sredni\n 3. Trudny\n 4. Informacje o poziomach trudnoœci\n\n Wybierz jedna z opcji : ");
    scanf("%d",&difficulty);
    printf("\n");
    Difficulty selectedDifficulty;
    while(1)
    {
        if(difficulty==1)
        {
            selectedDifficulty.difficultyLevel=1;
            selectedDifficulty.points=40;
            selectedDifficulty.damageValue=1.5;
            selectedDifficulty.healthValue=2;
            selectedDifficulty.manaValue=2;
            break;
        }
        else if(difficulty==2)
        {
            selectedDifficulty.difficultyLevel=1;
            selectedDifficulty.points=30;
            selectedDifficulty.damageValue=1.5;
            selectedDifficulty.healthValue=2;
            selectedDifficulty.manaValue=2;
            break;
        }
        else if(difficulty==3)
        {
            selectedDifficulty.difficultyLevel=1;
            selectedDifficulty.points=20;
            selectedDifficulty.damageValue=1.5;
            selectedDifficulty.healthValue=2;
            selectedDifficulty.manaValue=2;
            break;
        }
        else if(difficulty==4)
        {
            printf(" Poziom trudnosci okresla ilosc atrybutow oraz przeliczniki punktow zdrowia i many, oraz zadawane obrazenia.\n Na latwym poziomie otrzymujesz 50 punktow atrybutow, 2x punktow zdrowia i many,oraz 1.5x obrazen.\n Na srednim poziomie otrzymujesz 30 punktow atrybutow, 1x punktow zdrowia i many,oraz 1x obrazen\n Na trudny poziomie otrzymujesz 15 punktow atrybutow, 0.75x punktow zdrowia i many,oraz 0.75x obrazen\n\n Wybierz poziom trudnosci : ");
            scanf("%d",&difficulty);
            continue;
        }
        else
        {
            printf("Wybierz jeszcze raz : ");
            scanf("%d",&difficulty);
            continue;
        }
    }
    printf("\n\n");

    printf(" Podaj swoje imie : ");
    scanf("%s",selectedPlayerStats.playerName);

    printf("\n");
    printf(" Tworzenie postaci. \n\n 1. Wlasna postac.\n 2. Gotowa Postac (Uwaga atrybuty przydzielone po rowno).\n\n Wybierz opcje : ");
    scanf("%d",&fightOption);
    printf("\n");

    if(fightOption==1)
    {
        printf(" Masz %d punktów atrybutów.\n\n Rozdawaj je madrze gdyz nie mo¿esz wrocic do zadnego z nich aby zmienic! \n\n", selectedDifficulty.points);// Zak³adam, ¿e osoba graj¹ca umie przydzieliæ punkty i nie wyjdzie poza zakres
        selectedPlayerStats.playerAtributes=setPlayerAtributesManually(selectedDifficulty.points);
    }
    else if(fightOption==2)
    {
        selectedPlayerStats.playerAtributes=setPlayerAtributesAuto(selectedDifficulty.points);
    }
    printAtributes(selectedPlayerStats.playerAtributes);
    selectedPlayerStats=setPlayerStats(selectedPlayerStats, selectedDifficulty);
    printStats(selectedPlayerStats);

    gameSettings.difficulty=selectedDifficulty;
    gameSettings.playerstats=selectedPlayerStats;

    int goToNextLevel=runChapterOne(gameSettings);
                       if(goToNextLevel==TRUE)
    {
        goToNextLevel=FALSE;
        goToNextLevel=runChapterTwo(gameSettings);
    }
    system ("PAUSE");
}
