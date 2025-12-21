#include "Attack.h"

Attack::Attack() {
	attackName = "Run Away";
	attackDesc = "You run from the enemy to recuperate some health";//"You run from the enemy until it no longer sees you to get some time to plan for your next attack (keep in mind this doesn't always workout well)";
	attackDamage = 0;
	assignedNum = 2;
}

/// <summary>
/// 
/// </summary>
/// <param name="name"></param>
/// <param name="description"></param>
/// <param name="damage"></param>
Attack::Attack(string name, int damage, string description, int assignNum) {
	attackName = name;
	attackDamage = damage;
	attackDesc = description;
	assignedNum = assignNum;
}

Attack::Attack(string name, int damage, int assignNum) {
	attackName = name;
	attackDamage = damage;
	attackDesc = "...";
	assignedNum = assignNum;
}

void Attack::ShowAttackInfo() {
	cout << "\t " << assignedNum << " ) " << attackName << endl;
	cout << "\t  - Damage: " << attackDamage << endl;
	cout << "\t  - Description: " << attackDesc << endl;
	//cout << "		    " << attackDesc << endl;
	cout << endl;
}

void Attack::SetName(string name) {
	attackName = name;
}

void Attack::SetDamage(int damage) {
	attackDamage = damage;
}

void Attack::SetDesc(string desc) {
	attackDesc = desc;
}

void Attack::SetAssignedNum(int assignNum) {
	assignedNum = assignNum;
}

int Attack::GetAssignedNum() {
	return assignedNum;
}

int Attack::GetAttackDamage() {
	return attackDamage;
}

string Attack::GetAttackName() {
	return attackName;
}

string Attack::GetAttackDesc() {
	return attackDesc;
}