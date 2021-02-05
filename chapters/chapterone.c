#include "chapterone.h"
#define TRUE 1
#define FALSE 0
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
                    printf("Przeciwnik uciekl\n Czy chcesz go goniæ?\n 1. Tak \n 2. Nie\n Wybierz Opcje : ");
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
                                    printf("Przeciwnik zauwa¿a cie i atakuje\n");
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
                    printf("Przeciwnik œmieje sie i napiera");
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
        printf("Krogg zaczyna siê chwiac, ale jego potega wciaz jest wielka, uderza cie w glowe i odpycha krzyczac : To jeszcze nie koniec!!!\n\n");
        return TRUE;
    }
    if(fightOption==2)
    {
        printf("Krogg patrzy z zazenowaniem i wbija ci ostrze w serce. Umierasz.\n\n Wracasz do menu glownego");
        main();
    }
    return FALSE;
}
