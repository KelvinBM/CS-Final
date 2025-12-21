#ifndef PLAYER_ATTACK_H
#define PLAYER_ATTACK_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Attack {
public:
	void ShowAttackInfo();
	Attack();
	Attack(string name, int damage, string description, int assignNum);
	Attack(string name, int damage, int assignNum);
	void SetName(string name);
	void SetDamage(int damage);
	void SetDesc(string desc);
	void SetAssignedNum(int assignNum);
	int GetAssignedNum();
	int GetAttackDamage();
	string GetAttackName();
	string GetAttackDesc();

private:
	int assignedNum;
	string attackName;
	string attackDesc;
	int attackDamage;

};

#endif // PLAYER_ATTACK_H
