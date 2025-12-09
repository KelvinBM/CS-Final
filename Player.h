#ifndef TEXTBASED_FIGHTING_PLAYER_H
#define TEXTBASED_FIGHTING_PLAYER_H

#include <iostream>
#include <string>
#include <vector>
#include "Attack.h"

using namespace std;

class Player {
public:
    Player SelectPlayer();
    string GetName();
    int GetHealth();
    int GetAttackDamage();
    int GetCooldown();
    void ShowPlayerInfo();
    void AssignPlayerAttacks(vector<Attack> attacks);

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
    Player(string name, int health, int damage, int cooldown, int choice, vector<Attack> attacks);

private:
    string playerName;
    int playerHealth;
    int playerDamage;
    int playerCooldown;
    int characterChoice;
    vector<Attack> playerAttacks;
};

#endif //TEXTBASED_FIGHTING_PLAYER_H