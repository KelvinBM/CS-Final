#ifndef TEXT_BASED_GAME_H
#define TEXT_BASED_GAME_H

#include "Players.h"

class Game {
public:
	void PlayGame();
	Game();
	Game(Players heroesList, Players villainsList, int fightingRounds = 4);
	void FightingScenario1();
private:
	Player choice; // character choice of player
	Players heroes; // choose from
	Players villains; // fighting against
	int rounds;

};

#endif // TEXT_BASED_GAME_H
