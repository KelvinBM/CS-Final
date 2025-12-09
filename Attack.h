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
	Attack(string name, string description, int damage);

private:
	string attackName;
	string attackDesc;
	int attackDamage;

};

#endif // PLAYER_ATTACK_H
