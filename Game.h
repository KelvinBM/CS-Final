#ifndef TEXT_BASED_GAME_H
#define TEXT_BASED_GAME_H

#include "Players.h"

class Game {
public:
	Game();
	Game(int fightingRounds);
	Game(vector<Player> heroesList, vector<Player> villainsList, int fightingRounds = 4);
	void PlayGame();
	void FightingScenario1();
private:
	Player choice; // character choice of player
	vector<Player> heroes; // choose from
	vector<Player> villains; // fighting against
	int rounds;

};

#endif // TEXT_BASED_GAME_H
