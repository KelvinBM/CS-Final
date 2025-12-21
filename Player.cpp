#include "Player.h"
#include <chrono>
#include <thread>

Player::Player() {
    playerName = "Fortnite Default";
    playerHealth = 100;
    playerMaxHealth = playerHealth;
    playerDamage = 8;
    playerCooldown = 0;
    characterChoice = 0;

    playerAttacks;

    Attack attack1 = Attack();
}

Player::Player(string name, int health, int damage, int cooldown, int choice) {
    playerName = name;
    playerHealth = health;
    playerMaxHealth = playerHealth;
    playerDamage = damage;
    playerCooldown = cooldown;
    characterChoice = choice;
}

Player::Player(string name, int health, int damage, int cooldown, int choice, Attacks attacks) {
    playerName = name;
    playerHealth = health;
    playerMaxHealth = playerHealth;
    playerDamage = damage;
    playerCooldown = cooldown;
    characterChoice = choice;
    playerAttacks = attacks;
}

string Player::GetName() {
    return playerName;
}

int Player::GetPlayerChoice() {
    return characterChoice;
}

int Player::GetHealth() {
    return playerHealth;
}

int Player::GetMaxHealth() {
    return playerMaxHealth;
}

int Player::GetAttackDamage() {
    return playerDamage;
}

int Player::GetCooldown() {
    return playerCooldown;
}

Attacks Player::GetCharacterAttacks() {
    return playerAttacks;
}

Attack Player::GetChosenAttack(int attackChoice) {
    vector<Attack> availableAttacks = playerAttacks.GetAttacks();
    Attack currAttack;

    for (int i = 0; i < playerAttacks.GetNumAttacks(); i++) {
        currAttack = availableAttacks.at(i);

        if (attackChoice == currAttack.GetAssignedNum()) {
            return currAttack;
        }
    }

    // for if none are found
    currAttack.SetAssignedNum(-1);
    return currAttack;
}


void Player::ShowPlayerInfo() {
    cout << endl;
    //cout << playerName << " { " << characterChoice << " }" << endl;// player name and choice number //
    cout << playerName << endl;
    //this_thread::sleep_for(chrono::seconds(1));
    cout << endl;

    cout << "  Health: " << playerHealth << endl;
    //this_thread::sleep_for(chrono::seconds(1));

    cout << "  Damage: " << playerDamage << endl;
    //this_thread::sleep_for(chrono::seconds(1));

    cout << "  Cooldown: " << playerCooldown << endl;
    cout << endl;
}

void Player::ShowAttacksInfo() {
    playerAttacks.DisplayAttacksInfo();
}

void Player::AssignPlayerAttacks(Attacks attacks) {
    playerAttacks = attacks;
}

void Player::AssignPlayerHealth(int healthToAssign) {
    playerHealth = healthToAssign;
}

void Player::TakeDamage(int amount) {
    if (amount > 0)
        playerHealth -= amount;
    if (playerHealth < 0) 
        playerHealth = 0;
}

void Player::HealUp() {
    int healUp = 5;
    int currHealth = GetHealth();
    if (healUp + currHealth <= currHealth) {
        AssignPlayerHealth(healUp + currHealth);
    }
    else {
        AssignPlayerHealth(GetMaxHealth());
    }
}

void Player::HealUp(int healthToHeal) {

}