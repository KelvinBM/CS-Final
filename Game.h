#ifndef TEXT_BASED_GAME_H
#define TEXT_BASED_GAME_H

#include "Players.h"

class Game {
public:
	Game();
	Game(int fightingRounds);
	Game(vector<Player> heroesList, vector<Player> villainsList, int fightingRounds = 4);
	void PlayGame();
	void RunTheFights();
	void TimeToAttack();
	void EnemyAttacks();
	void FightingScenario1();
	void EnemyInDisdainLevel1();
	void EnemyInDisdainLevel2();
	void SpaceMax();
	void Waiting();
private:
	Player chosenPlayer; // character choice of player
	Player enemy;
	vector<Player> heroes; // choose from
	vector<Player> villains; // fighting against
	int rounds;

};

#endif // TEXT_BASED_GAME_H
