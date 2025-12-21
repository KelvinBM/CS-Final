#ifndef ATTACKS_H
#define ATTACKS_H

#include "Attack.h"

class Attacks {
public:
	void AssignAttacks(int attackAmount);
	void AssignAttacks(vector<Attack> attacksToAssign);
	void AssignAttack(Attack attack);
	void AssignAttack(string name, int damage, int assignedNum);
	void AssignAttack(string name, int damage, string desc, int assignedNum);

	int GetNumAttacks();
	vector<Attack> GetAttacks();

	void DisplayAttacksInfo();

private:
	vector<Attack> attacks;
	int numOfAttacks = 0;
};

#endif // !ATTACKS_H

