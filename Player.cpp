#include "Player.h"

Player::Player() {
    playerName = "default";
    playerHealth = 100;
    playerDamage = 8;
    playerCooldown = 0;
    characterChoice = 0;

    playerAttacks;

    Attack attack1 = Attack();
}

Player::Player(string name, int health, int damage, int cooldown, int choice) {
    playerName = name;
    playerHealth = health;
    playerDamage = damage;
    playerCooldown = cooldown;
    characterChoice = choice;
}

Player::Player(string name, int health, int damage, int cooldown, int choice, vector<Attack> attacks) {
    playerName = name;
    playerHealth = health;
    playerDamage = damage;
    playerCooldown = cooldown;
    characterChoice = choice;
    playerAttacks = attacks;
}

string Player::GetName() {
    return playerName;
}

int Player::GetHealth() {
    return playerHealth;
}

int Player::GetAttackDamage() {
    return playerDamage;
}

int Player::GetCooldown() {
    return playerCooldown;
}

void Player::ShowPlayerInfo() {
    cout << playerName << " { " << characterChoice << " }" << endl;// player name and choice number //
    cout << "  Health: " << playerHealth << endl;
    cout << "  Damage: " << playerDamage << endl;
    cout << "  Cooldown: " << playerCooldown << endl << endl;
}

void Player::AssignPlayerAttacks(vector<Attack> attacks) {
    playerAttacks = attacks;
}
