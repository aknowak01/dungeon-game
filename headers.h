#ifndef HEADERS_H_INCLUDED
#define HEADERS_H_INCLUDED
typedef struct
{
    int strength;
    int wisdom;
    int agility;
    int health;
    int mana;
} Atributes;
typedef struct
{
    char playerName[30];
    float damage;
    float criticalDamage;
    float magicDamage;
    float criticalChance;
    float dodgeChance;
    float health;
    float manapoints;
    Atributes playerAtributes;
} PlayerStats;
typedef struct
{
    int type;
    float health;
    float damage;
} Enemy;
typedef struct
{
    int difficultyLevel;
    int points;
    float damageValue;
    float healthValue;
    float manaValue;

}Difficulty;
typedef struct
{
    PlayerStats playerstats;
    Difficulty difficulty;
}GameSettings;

#endif // HEADERS_H_INCLUDED
