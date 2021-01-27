#ifndef RANDOMEVENTS_H_INCLUDED
#define RANDOMEVENTS_H_INCLUDED

typedef struct {
    short int strength;
    short int wisdom;
    short int agility;
    short int health;
    short int mana;
} Attributes;

typedef struct {
    float damage;
    float criticalDamage;
    float magicDamage;
    float criticalChance;
    float dodgeChance;
    float health;
    float manapoints;
} PlayerSkills;

typedef struct {
    PlayerSkills playerSkills;
    Attributes playerAttributes;
} PlayerStats;


typedef struct {
    int difficultyId;
    int difficultyPointsValue;
} Difficulty;


typedef struct {
    char playerName;
    PlayerStats playerStats;
    Difficulty difficulty
} GameState;

typedef struct {
    float damage;
    float health;
} Enemy;

int getOption();

Difficulty getDifficulty();

char getPlayerName();

Attributes getPlayerAttributes(Difficulty difficulty);

Attributes getDefaultPlayerAttributes(Difficulty difficulty);

Attributes selectPlayerAttributes(Difficulty difficulty);

PlayerSkills getPlayerSkills(Attributes attributes, Difficulty difficulty);

void viewStats(GameState gameState);

int startBattle(GameState gameState);

#endif // RANDOMEVENTS_H_INCLUDED
