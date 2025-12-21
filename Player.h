#ifndef TEXTBASED_FIGHTING_PLAYER_H
#define TEXTBASED_FIGHTING_PLAYER_H

#include <iostream>
#include <string>
#include <vector>
#include "Attack.h"
#include "Attacks.h"

using namespace std;

class Player{
public:

    string GetName();
    int GetPlayerChoice();
    int GetHealth();
    int GetMaxHealth();
    int GetAttackDamage();
    int GetCooldown();
    int GetTotalAttacksCount();
    Attacks GetCharacterAttacks();
    Attack GetChosenAttack(int attackChoice);
    void ShowPlayerInfo();
    void ShowAttacksInfo();
    void AssignPlayerAttacks(Attacks attacks);
    void AssignPlayerHealth(int healthToAssign);
    void TakeDamage(int amount);
    void HealUp();
    void HealUp(int healthToHeal);

    Player();
    /// <summary>
    /// I realized the format for this by accident while writing some notes in my vs file containing all the Zybook reading and lab notes 
    /// </summary>
    /// <param name="name">: Name</param>
    /// <param name="health">: Health</param>
    /// <param name="damage">: Attack damage</param>
    /// <param name="cooldown">: Attack cooldown</param>
    /// <param name="choice">: Choice number</param>
    Player(string name, int health, int damage, int cooldown, int choice);
    /// <summary>
    /// I realized the format for this by accident while writing some notes in my vs file containing all the Zybook reading and lab notes 
    /// </summary>
    /// <param name="name">: Name</param>
    /// <param name="health">: Health</param>
    /// <param name="damage">: Attack damage</param>
    /// <param name="cooldown">: Attack cooldown</param>
    /// <param name="choice">: Choice number</param>
    /// <param name="attacks">: Attacks of character</param>
    Player(string name, int health, int damage, int cooldown, int choice, Attacks attacks);

private:
    string playerName;
    int playerHealth;
    int playerMaxHealth;
    int playerDamage;
    int playerCooldown;
    int characterChoice;
    //bool dead = false;
    Attacks playerAttacks;
};

#endif //TEXTBASED_FIGHTING_PLAYER_H