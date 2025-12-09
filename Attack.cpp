#include "Attack.h"

Attack::Attack() {
	attackName = "Run Away";
	attackDesc = "You run from the enemy until it no longer sees you to get some time to plan for your next attack (keep in mind this doesn't always workout well)";
	attackDamage = 0;
}

Attack::Attack(string name, string description, int damage) {
	attackName = name;
	attackDesc = description;
	attackDamage = damage;
}

void Attack::ShowAttackInfo() {
	cout << "   Attack: " << attackName << endl;
	cout << "      - Damage: " << attackDamage << endl;
	cout << "      - Description: " << endl;
	cout << "		    " << attackDesc << endl;
}
