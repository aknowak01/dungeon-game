#include "chaptertwo.h"
#define TRUE 1
#define FALSE 0
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
                    printf("Przeciwnik uciekl\n Czy chcesz go goniæ?\n 1. Tak \n 2. Nie\n Wybierz Opcje : ");
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
                                printf(" Widzisz placzaca kobiete, podchodzisz blizej.\n\n Pytasz sie : Kim jestes?.\n\n Odpowiada : Idz glupcze, obudziles tego potwora, teraz znowu bedzie dreczyl swiat\n\n Odpowiadasz : Przepraszam nie mailem tego za cel, przyszedlem tu na prosbe maga z okolicznej wioski, podobno potwory przeszkadza³y bardziej niz zwykle. \n\n Duch odpowiada : Wybacz nie powinnam pochopnie cie oceniac. Jestem Lisandra, zona Krogga. Jedynym wyjsciem aby przestal plugawic ten swiat jest zniszczenie go.\n\n Ruszajmy bede ci towarzyszyc.\n\n");
                                printf("\n\n Zblizasz sie do glownych drzwi,.\n\n Lisandra leci za toba.\n\n");
                                return runBossFightTwo(gameSettings);

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
    return FALSE;
}
