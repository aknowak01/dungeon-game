#include "randomevents.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define N 10
#include "entities/player.h"
struct enemy
{
    float health;
    float damage;
    float magicDamage;
} skeleton,zombie;
void enemytype1damage(int dificulty)
{
    srand(time(0));
    if(dificulty==1)
    {
        skeleton.damage=(rand()%400)+200;
        zombie.damage=(rand()%300)+100;
    }
    else if(dificulty==2)
    {
        skeleton.damage=(rand()%600)+400;
        zombie.damage=(rand()%450)+200;
    }
    else if(dificulty==3)
    {
        skeleton.damage=(rand()%800)+600;
        zombie.damage=(rand()%650)+300;
    }
}
void enemytype1health()
{
    skeleton.health=4000;
    zombie.health=6000;
}
int fight1(int dificulty)
{
    int enemy=0,option,goaway,attackchance;
    float move;
    srand(time(0));
    enemytype1damage(dificulty);
    enemytype1health();
    enemy=rand()%2;
    if(enemy==0)
    {
        printf(" Walczysz z Szkieletem.\n");
        while(1)
        {
            printf(" Zdrowie Szkieleta : %.2f\n Twoje zdrowie : %.2f\n\n 1.Atak.\n 2.Atak magiczny.\n 3.Próba ucieczki. 4.Unik i atak.\n\n Wybierz opcje :  ",skeleton.health,player.health);
            scanf("%d",&option);
            if(skeleton.health-player.damage>100||skeleton.health-player.magicDamage>0)
            {
                if(player.health-skeleton.damage<100)
                {
                    return 3;
                }
                else if(option==1)
                {
                    skeleton.health=skeleton.health-player.damage;
                    player.health=player.health-skeleton.damage;
                }
                else if(option==2)
                {
                    skeleton.health=skeleton.health-player.magicDamage;
                    player.health=player.health-skeleton.damage;
                }
                else if(option==3)
                {
                    goaway=rand()%10;
                    if(goaway==1||goaway==9)
                    {
                        return 2;
                    }
                    else player.health=player.health-skeleton.damage;
                }
                else if(option==4)
                {
                    move=rand()%100-player.dodgeChance;
                    if(move>40)
                    {
                        skeleton.health=skeleton.health-player.damage;
                    }
                    else
                    {
                        skeleton.health=skeleton.health-player.damage;
                        player.health=player.health-skeleton.damage;
                    }
                }
            }
            else return 1;
        }
    }
    else if(enemy==1)
    {
        printf(" Walczysz z Zombie.\n");
        while(1)
        {
            printf(" Zdrowie Zombie : %.2f\n Twoje zdrowie : %.2f\n\n 1.Atak.\n 2.Atak magiczny.\n 3.Próba ucieczki.\n 4.Unik i atak.\n\n Wybierz opcje :  ",zombie.health,player.health);
            scanf("%d",&option);
            if(zombie.health-player.damage>100)
            {
                if(player.health-zombie.damage<100)
                {
                    return 3;
                }
                else if(option==1)
                {
                    zombie.health=zombie.health-player.damage;
                    player.health=player.health-zombie.damage;
                }
                else if(option==2)
                {
                    zombie.health=skeleton.health-player.magicDamage;
                    player.health=player.health-zombie.damage;
                }
                else if(option==3)
                {
                    goaway=rand()%10;
                    if(goaway==1||goaway==9)
                    {
                        return 2;
                    }
                    else player.health=player.health-zombie.damage;
                }
                else if(option==4)
                {
                    move=rand()%100-player.dodgeChance;

                    if(move>40)
                    {
                        zombie.health=zombie.health-player.damage;
                    }
                    else
                    {
                        zombie.health=zombie.health-player.damage;
                        player.health=player.health-zombie.damage;
                    }
                }
            }
            else return 1;
        }
    }
}
void chapter1(int dificulty)
{
    int option1,battle,option2,boss;
    while(1)
    {
        option1=options();
        if(option1==1)
        {
            battle=fight1(dificulty);
            option2=bresult(battle);
            if(option2==1)
            {
                option1=options();
                if(option1=1)
                {
                    printf("Przeciwnik uciekl\n Czy chcesz go gonić?\n 1. Tak \n 2. Nie\n Wybierz Opcje : ");
                    scanf("%d",&option1);
                    if(option1==1)
                    {
                        battle=fight1(dificulty);
                        option2=bresult(battle);
                        if(option2==1)
                        {
                            stats(dificulty);
                            printf("Znajdujesz magiczna skrzynie,\n\n 1. Otworzyc.\n\n 2. Nie otwierac\n\n 3. Sprobuj zniszczyc skrzynie\n\n Wybierz opcje : ");
                            scanf("%d",&option1);
                            if(option1==1||option1==3)
                            {
                                printf(" Znajdujesz Ostrze Zniszczonego Krola.\n\n Dostajesz dodatkowe obrazenia.\n\n Wraz z wyciagniecie miecza wyleciala dziwna esencja i zniknela.");
                                player.damage+=400;
                                printf("\n\n Kiedy przemierzasz nastepny korytarz czujesz jak jakas dziwna energia probuje cie pochlonac.\n\n Wbiegasz do pokoju naprzeciwko.\n\n");
                                bossfight1();
                                break;
                            }
                            else if (option1==2)
                            {
                                option1=options();
                                if(option1==1)
                                {
                                    battle=fight1(dificulty);
                                    option2=bresult(battle);
                                    bossfight1();
                                    break;
                                }
                                else
                                {
                                    printf("Przeciwnik zauważa cie i atakuje\n");
                                    battle=fight1(dificulty);
                                    option2=bresult(battle);
                                    printf("Po walce \n");
                                    bossfight1();
                                    break;
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
        }
        else if(option1==2)
        {
            continue;
        }
    }
}
int bossfight1()
{
    int attack1,option1,bosshealth=22000;
    printf("Tajemniczy glos mowi: Ten zamek zamieni sie w twoja trumne.\n\n Wybierz odpowiedz.\n\n 1. Bede walczyc do konca!\n 2.Poddaje sie, oszczedz mnie.\n\n Wybierz opcje : ");
    scanf("%d",&option1);
    if(option1==1)
    {
        printf("\n\n Mowisz: Bede walczyc do konca, nie przestraszy mnie byle duch! ");
        printf("\n Tajemniczy Glos odpowiada: A wiec walczmy, od kilku set lat sie nie ruszalem, nareszcie nadszedl czas.");
        printf("\n\n Przeciwnik Wylania sie z cienia, okazuje sie ze to dusza Krogga, wlasciciela miecza ktory znalazles.");
        while(1)
        {
            printf("\n\nTwoje zdrowie %f\nZdrowie Krogga %d\n\n Wybierz opcje ataku : \n 1. Zaatakuj mieczem\n 2. Odwroc jego uwage rzucajac wlocznia ktora lezy na ziemi\n 3. Rzuc czar\n\n Wybierz opcje : ",player.health,bosshealth);
            scanf("%d",&attack1);
            if(bosshealth-player.damage>0||bosshealth-player.magicDamage>0)
            {
                if(attack1==1)
                {
                    bosshealth=bosshealth-player.damage;
                    player.health=player.health-200;
                    continue;
                }
                else if(attack1==2)
                {
                    printf("Przeciwnik śmieje sie i napiera");
                    player.health-=200;
                    continue;
                }
                else if(attack1==3)
                {
                    bosshealth-=player.magicDamage;
                    player.health-=200;
                    continue;
                }
                else if(player.health<200)
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
        chapter2();
    }
    if(option1==2)
    {
        printf("Krogg patrzy z zazenowaniem i wbija ci ostrze w serce. Umierasz.\n\n Wracasz do menu glownego");
        main();
    }
}
void chapter2(int dificulty)
{
    int option1,battle,option2,boss;
    printf("\n Kiedy upadasz widzisz jak duch Krogga leci korytarzem i zawala mur. Musisz znalezc inna droge.\n\n Kiedy dochodzisz do siebie");
    while(1)
    {
        option1=options();
        if(option1==1)
        {
            battle=fight1(dificulty);
            option2=bresult(battle);
            if(option2==1)
            {
                option1=options();
                if(option1=1)
                {
                    printf("Przeciwnik uciekl\n Czy chcesz go gonić?\n 1. Tak \n 2. Nie\n Wybierz Opcje : ");
                    scanf("%d",&option1);
                    if(option1==1)
                    {
                        battle=fight1(dificulty);
                        option2=bresult(battle);
                        if(option2==1)
                        {
                            stats(dificulty);
                            printf("Znajdujesz magiczna skrzynie,\n\n 1. Otworzyc.\n\n 2. Nie otwierac\n\n 3. Sprobuj zniszczyc skrzynie\n\n Wybierz opcje : ");
                            scanf("%d",&option1);
                            if(option1==1||option1==3)
                            {
                                printf(" Widzisz placzaca kobiete, podchodzisz blizej.\n\n Pytasz sie : Kim jestes?.\n\n Odpowiada : Idz glupcze, obudziles tego potwora, teraz znowu bedzie dreczyl swiat\n\n Odpowiadasz : Przepraszam nie mailem tego za cel, przyszedlem tu na prosbe maga z okolicznej wioski, podobno potwory przeszkadzały bardziej niz zwykle. \n\n Duch odpowiada : Wybacz nie powinnam pochopnie cie oceniac. Jestem Lisandra, zona Krogga. Jedynym wyjsciem aby przestal plugawic ten swiat jest zniszczenie go.\n\n Ruszajmy bede ci towarzyszyc.\n\n");
                                player.damage+=400;
                                printf("\n\n Zblizasz sie do glownych drzwi,.\n\n Lisandra leci za toba.\n\n");
                                bossfight2();
                                break;
                            }
                            else if (option1==2)
                            {
                                option1=options();
                                if(option1==1)
                                {
                                    battle=fight1(dificulty);
                                    option2=bresult(battle);
                                    bossfight1();
                                    break;
                                }
                                else
                                {
                                    printf("Przeciwnik zauważa cie i atakuje\n");
                                    battle=fight1(dificulty);
                                    option2=bresult(battle);
                                    printf("Po walce \n");
                                    bossfight2();
                                    break;
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
        }
        else if(option1==2)
        {
            printf("\n Nie ma innej drogi\n\n");
            continue;
        }
    }
}
void bossfight2()
{
    int attack1,option1,bosshealth=35000,zycietamtejpostaci=1;

    printf("Kroczysz ruinami zamku wraz z postacia X. Z oddali slyszysz dziwny halas. Czy chcesz to sprawdzic? 1. Tak, idz w strone tajemnej komanty 2. Nie, idz dalej korytarzem");
    scanf("%d",&option1);
    if (option1==1)
    {

        printf("W komnacie widzisz tron, a na nim siedzi Krogg tylem do drzwi. Atakujesz go z zaskoczenia, zadajac dodatkowe obrazenia. Krogg smieje sie i mowi ""Odwaznie!"", po czym podejmuje z toba walke.");
        bosshealth-=5000;

    }
    else if (option1==2)
    {
        zycietamtejpostaci=0;
        ("Po zrobieniu kilku krokow slyszysz krzyk za soba. To Krogg zabil twojego towarzysza z zaskoczenia i uciekl do sali tronowej! Czy biegniesz za nim? 1. Tak 2. Nie");
        scanf("%d",&option1);
        if (option1==1)
        {
            printf("To pulapka! Tuz za drzwiami Krogg uderza cie z zaskoczenia, jednak ty podejmujesz walke. ""Czy sadzisz ze mzoesz mnie pokonac?"" smieje sie Krogg podczas walki.");
            player.health-=300;
        }
        if (option1==2)
        {
            printf("Po kolejnym zignorowaniu Krogga on atakuje cie z tylu ze zwiekszona sila, umierasz. Wracasz do menu.");
            main();
        }

        if (option1==1) //czyli ze jestes w sali tronowej i podjales walke XD bo albo od razu dales 1 i ci idzie na dol, jak dales 2 to potem musisz dac 1 zeby wyladowac w komnacie i walczyc
        {

            while(1)
            {
                printf("\n\nTwoje zdrowie %f\nZdrowie Krogga %d\n\n Wybierz opcje ataku : \n 1. Zaatakuj mieczem\n2. Rzuc czar\n\n Wybierz opcje : ",player.health,bosshealth);

                scanf("%d",&attack1);

                if(bosshealth-player.damage>0||bosshealth-player.magicDamage>0)
                {
                    if(attack1==1)
                    {
                        bosshealth=bosshealth-player.damage;
                        player.health=player.health-300;
                        if(zycietamtejpostaci==1) bosshealth-=150;
                        continue;
                    }


                    else if(attack1==2)
                    {
                        bosshealth-=player.magicDamage;
                        player.health-=200;
                        if(zycietamtejpostaci==1) bosshealth-=100;
                        continue;
                    }


                }
            }

        }
    }
}
int options()
{
    int option1;
    printf(" Zblizasz sie do drzwi, na twojej drodze stoi przeciwnik.\n\n"
           " Wybierz dzialanie.\n\n"
           " 1.Zaatakuj przeciwnika.\n"
           " 2.Sprawdź czy jest inne przejscie.\n"
           "\n\n Wybierz Opcje: ");
    scanf("%d",&option1);
    return option1;
}
int bresult(int battle)
{
    if(battle==1)
    {
        printf("\nWygrana!\n");
        return 1;
    }
    else if(battle=3)
    {
        printf("\nPorazka\n");
        return 0;
    }
    else if(battle=2)
    {
        printf("\nUdalo ci sie uciec\n");
        return 1;
    }
}
void game()
{
    int option1,points,dificulty,temp,battle,leng;
    char name[N];
    printf(" Wybierz Poziom trudnoœci.\n\n 1. Latwy\n 2. Sredni\n 3. Trudny\n 4. Informacje o poziomach trudnoœci\n\n Wybierz jedna z opcji : ");
    scanf("%d",&dificulty);
    printf("\n");
    while(1)
    {
        if(dificulty==1)
        {
            points=40;
            break;
        }
        else if(dificulty==2)
        {
            points=30;
            break;
        }
        else if(dificulty==3)
        {
            points=20;
            break;
        }
        else if(dificulty==4)
        {
            printf(" Poziom trudnosci okresla ilosc atrybutow oraz przeliczniki punktow zdrowia i many, oraz zadawane obrazenia.\n Na latwym poziomie otrzymujesz 50 punktow atrybutow, 2x punktow zdrowia i many,oraz 1.5x obrazen.\n Na srednim poziomie otrzymujesz 30 punktow atrybutow, 1x punktow zdrowia i many,oraz 1x obrazen\n Na trudny poziomie otrzymujesz 15 punktow atrybutow, 0.75x punktow zdrowia i many,oraz 0.75x obrazen\n\n Wybierz poziom trudnosci : ");
            scanf("%d",&dificulty);
            continue;
        }
        else
        {
            printf("Wybierz jeszcze raz : ");
            scanf("%d",&dificulty);
            continue;
        }
    }
    temp=dificulty;
    printf("\n\n");
    printf(" Podaj swoje imie : ");
    for(leng=0; leng<0; leng++)
    {
        scanf("%s",name[leng]);
    }
    printf("\n");
    printf(" Tworzenie postaci. \n\n 1. Wlasna postac.\n 2. Gotowa Postac (Uwaga atrybuty przydzielone po rowno).\n\n Wybierz opcje : ");
    scanf("%d",&option1);
    printf("\n");
    if(option1==1)
    {
        printf(" Masz %d punktów atrybutów.\n\n Rozdawaj je madrze gdyz nie mo¿esz wrocic do zadnego z nich aby zmienic! \n\n",points);// Zak³adam, ¿e osoba graj¹ca umie przydzieliæ punkty i nie wyjdzie poza zakres
        playeratri(points);
    }
    else if(option1==2)
    {
        autoatri(points);
    }
    stats(temp);
    viewstats(name);
    chapter1(dificulty);
    system ("PAUSE");
}
