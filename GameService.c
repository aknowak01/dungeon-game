#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "GameService.h"

/**
 * Zwraca:
 * 1 - jeżeli gra ma się rozpocząć
 * 0 - jeżeli wyjście
 */
int getOption() {
    int inputOption;
    printf("Mroczne Czasy.\n \n "
           "1. Rozpoczęcie Gry. \n "
           "2. Wyjście.\n\n "
           "Wybierz opcje : ");

    scanf("%d", &inputOption);
    printf("\n");

    while (1) {
        switch (inputOption) {
            case 1:
                return 1;
            case 2:
                printf("Zamykanie gry...");
                return 0;
            default:
                printf(" Wybierz jeszcze raz : ");
                scanf("%d", &inputOption);
                printf("\n");
                break;
        }
    }
}

/**
 * Zwraca poziom trudności gry
 */
Difficulty getDifficulty() {
    int inputDifficulty;
    Difficulty selectedDifficulty;
    printf(" Wybierz Poziom trudności.\n\n "
           "1. Latwy\n "
           "2. Sredni\n "
           "3. Trudny\n "
           "4. Informacje o poziomach trudności\n\n"
           " Wybierz jedna z opcji : ");

    scanf("%d", &inputDifficulty);
    while (1) {
        switch (inputDifficulty) {
            case 1: // Łatwy
                selectedDifficulty.difficultyId = 1;
                selectedDifficulty.difficultyPointsValue = 40;
                return selectedDifficulty;

            case 2: // Średni
                selectedDifficulty.difficultyId = 2;
                selectedDifficulty.difficultyPointsValue = 30;
                return selectedDifficulty;
            case 3: // Trudny
                selectedDifficulty.difficultyId = 3;
                selectedDifficulty.difficultyPointsValue = 20;
                return selectedDifficulty;
            case 4: // Ustawienia
                printf(" Poziom trudnosci okresla ilosc atrybutow oraz przeliczniki punktow zdrowia i many, "
                       "oraz zadawane obrazenia.\n "
                       "Na latwym poziomie otrzymujesz "
                       "- 50 punktow atrybutow, "
                       "- 2x punktow zdrowia i many, "
                       "- 1.5x obrazen.\n "
                       "Na srednim poziomie otrzymujesz "
                       "- 30 punktow atrybutow, "
                       "- 1x punktow zdrowia i many, "
                       "- 1x obrazen\n "
                       "Na trudny poziomie otrzymujesz "
                       "- 15 punktow atrybutow, "
                       "- 0.75x punktow zdrowia i many,"
                       "- 0.75x obrazen\n\n "
                       "Wybierz poziom trudnosci : ");

                scanf("%d", &inputDifficulty);
                continue;
            default:
                printf("Wybierz jeszcze raz : ");
                scanf("%d", &inputDifficulty);
                continue;
        }
    }
}

/**
 * Zwraca nazwę gracza
 */
char getPlayerName() {
    char name;
    printf(" Podaj swoje imie : ");
    scanf("%s", &name);
    return name;
}

Attributes getPlayerAttributes(Difficulty difficulty) {
    int inputOption;
    printf(" Tworzenie postaci. \n\n "
           "1. Wlasna postac.\n "
           "2. Gotowa Postac (Uwaga atrybuty przydzielone po rowno).\n\n "
           "Wybierz opcje : ");
    scanf("%d", &inputOption);

    switch (inputOption) {
        case 1:
            return getDefaultPlayerAttributes(difficulty);
        case 2:
            return selectPlayerAttributes(difficulty);
        default:
            printf("Błędny wybór. Ustawiam domyślne ustawienia...");
            return getDefaultPlayerAttributes(difficulty);
    }
}

Attributes getDefaultPlayerAttributes(Difficulty difficulty) {
    int maxPoints = difficulty.difficultyPointsValue;
    short int expandedPoints = (short int) (maxPoints - maxPoints * 0.8);

    Attributes defaultAttributes;
    defaultAttributes.strength = expandedPoints;
    defaultAttributes.wisdom = expandedPoints;
    defaultAttributes.agility = expandedPoints;
    defaultAttributes.health = expandedPoints;
    defaultAttributes.mana = expandedPoints;
    return defaultAttributes;
}

Attributes selectPlayerAttributes(Difficulty difficulty) {
    int maxPoints = difficulty.difficultyPointsValue;
    int remainingPoints = maxPoints;
    int inputVariable;
    Attributes currentAttributes;
    printf(" Masz %d punktów atrybutów.\n\n Rozdawaj je madrze gdyz nie możesz wrocic do zadnego z nich aby zmienic! \n\n",
           maxPoints);
    //TODO - Czy nie da się tego ujednolicić?
    printf("\n 1.Sila : ");
    scanf("%d", &inputVariable);
    remainingPoints = remainingPoints - inputVariable;
    currentAttributes.strength = (short int) inputVariable;
    printf("\n Zosta�o ci %d punktow.\n ", remainingPoints);

    printf("\n 2.Madrosc : ");
    scanf("%d", &inputVariable);
    remainingPoints = remainingPoints - inputVariable;
    currentAttributes.strength = (short int) inputVariable;
    printf("\n Zosta�o ci %d punktow.\n ", remainingPoints);

    printf("\n 3.Zrecznosc : ");
    scanf("%d", &inputVariable);
    remainingPoints = remainingPoints - inputVariable;
    currentAttributes.strength = (short int) inputVariable;
    printf("\n Zosta�o ci %d punktow.\n ", remainingPoints);

    printf("\n 4.Zdrowie : ");
    scanf("%d", &inputVariable);
    remainingPoints = remainingPoints - inputVariable;
    currentAttributes.strength = (short int) inputVariable;
    printf("\n Zosta�o ci %d punktow.\n ", remainingPoints);

    printf("\n 5.Magia : ");
    scanf("%d", &inputVariable);
    currentAttributes.strength = (short int) inputVariable;

    return currentAttributes;
}

PlayerSkills getPlayerSkills(Attributes attributes, Difficulty difficulty) {
    PlayerSkills playerSkills;
    int selectedDifficulty = difficulty.difficultyId;

    //TODO - Czy nie da się tego ujednolicić?
    if (selectedDifficulty == 1) {
        playerSkills.damage = (short int) (100 * 1.5 * (1 + (0.75 * attributes.strength)));
        playerSkills.criticalDamage = (short int) (200 + playerSkills.damage);
        playerSkills.magicDamage = (short int) (100 * (1 + (0.80 * attributes.wisdom)));
        playerSkills.criticalChance = (short int) (10 + (2 * attributes.agility));
        playerSkills.dodgeChance = (short int) (15 + (2 * attributes.agility));
        playerSkills.health = (short int) (1000 * 2 * (2 * 0.5 * attributes.health));
        playerSkills.manapoints = (short int) (2000 * 2 + (200 * 0.25 * attributes.mana));
    } else if (selectedDifficulty == 2) {
        playerSkills.damage = (short int) (100 * (1 + (0.75 * attributes.strength)));
        playerSkills.criticalDamage = (short int) (200 + playerSkills.damage);
        playerSkills.magicDamage = (short int) (100 * (1 + (0.80 * attributes.wisdom)));
        playerSkills.criticalChance = (short int) (10 + (2 * attributes.agility));
        playerSkills.dodgeChance = (short int) (15 + (2 * attributes.agility));
        playerSkills.health = (short int) (1000 * (2 * 0.5 * attributes.health));
        playerSkills.manapoints = (short int) (2000 + (200 * 0.25 * attributes.mana));
    } else {
        playerSkills.damage = (short int) (100 * 0.75 * (1 + (0.75 * attributes.strength)));
        playerSkills.criticalDamage = (short int) (200 + playerSkills.damage);
        playerSkills.magicDamage = (short int) (100 * (1 + (0.80 * attributes.wisdom)));
        playerSkills.criticalChance = (short int) (10 + (2 * attributes.agility));
        playerSkills.dodgeChance = (short int) (15 + (2 * attributes.agility));
        playerSkills.health = (short int) (1000 * 0.75 * (2 * 0.5 * attributes.health));
        playerSkills.manapoints = (short int) (2000 * 0.75 + (200 * 0.25 * attributes.mana));
    }

    return playerSkills;
}


void viewStats(GameState gameState) {
    PlayerSkills playerSkills = gameState.playerStats.playerSkills;
    Attributes attributes = gameState.playerStats.playerAttributes;

    printf(" Twoje Statystyki\n\n");
    printf(" Imie : %c\n", gameState.playerName);
    printf(" Sila : %d,  obrazenia : %.2f i obrazenia krytyczne %.2f\n", attributes.strength, playerSkills.damage,
           playerSkills.criticalDamage);
    printf(" Zrecznosc : %d,  Szansa na obrazenia krytyczne : %.2f%% i szansa na unik %.2f%%\n", attributes.agility,
           playerSkills.criticalChance, playerSkills.dodgeChance);
    printf(" Wiedza : %d i obrazenia magiczne : %.2f\n", attributes.wisdom, playerSkills.magicDamage);
    printf(" Zdrowie : %d i punkty zdrowia : %.2f\n", attributes.health, playerSkills.health);
    printf(" Magia : %d i punkty magii : %.2f\n\n", attributes.mana, playerSkills.manapoints);
}

int startBattle(GameState gameState) {
    int difficultyId = gameState.difficulty.difficultyId;
    int option, goaway, move;

    PlayerSkills playerSkills = gameState.playerStats.playerSkills;

    Enemy skeleton;
    Enemy zombie;

    skeleton.health = 4000;
    zombie.health = 6000;

    while (1) {
        srand(time(0));
        if (difficultyId == 1) {
            skeleton.damage = (float)((rand() % 400) + 200);
            zombie.damage = (float)((rand() % 300) + 100);
        } else if (difficultyId == 2) {
            skeleton.damage = (float)((rand() % 600) + 400);
            zombie.damage = (float)((rand() % 450) + 200);
        } else if (difficultyId == 3) {
            skeleton.damage = (float)((rand() % 800) + 600);
            zombie.damage = (float)((rand() % 650) + 300);
        }

        printf(" Walczysz z Szkieletem.\n "
               "Zdrowie Szkieleta : %f\n "
               "Twoje zdrowie : %f\n\n "
               ""
               "1.Atak.\n "
               "2.Atak magiczny.\n "
               "3.Pr�ba ucieczki. "
               "4.Unik i atak.\n\n "
               ""
               "Wybierz opcje :  ", skeleton.health, playerSkills.health);

        scanf("%d", &option);
        if (skeleton.health - playerSkills.damage > 0) {
            if (option == 1) {
                skeleton.health = skeleton.health - playerSkills.damage;
                playerSkills.health = playerSkills.health - skeleton.damage;
            } else if (option == 2) {
                skeleton.health = skeleton.health - playerSkills.magicDamage;
                playerSkills.health = playerSkills.health - skeleton.damage;
            } else if (option == 3) {
                goaway = rand() % 10;
                if (goaway == 1 || goaway == 9) {
                    return 2;
                } else playerSkills.health = playerSkills.health - skeleton.damage;
            } else if (option == 4) {
                move = rand() % 100 - playerSkills.dodgeChance;
            }
        } else return 1;
    }
}

