#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#include "headers.h"
#include "entities/player.h"
#include "chapters/chapterone.h"
#include "chapters/chaptertwo.h"
#include "core/fightcore.h"

void main()
{
    int option;
    printf(" Legenda Krogga.\n \n 1. Rozpoczêcie Gry. \n 2. Wyjœcie.\n\n Wybierz opcje : ");
    scanf("%d",&option);
    printf("\n");
    while(1)
    {
        if(option==1)
        {
            runGame();
            break;
        }
        else if(option==2)
        {
            break;
        }
        else
        {
            printf(" Wybierz jeszcze raz : ");
            scanf("%d",&option);
            printf("\n");
        }
    }
}

void runGame()
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

