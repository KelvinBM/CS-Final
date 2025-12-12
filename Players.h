#ifndef PLAYERS_LIST_H
#define PLAYERS_LIST_H

#include "Player.h"

class Players : public Player{
public:
	vector<Player> GetPlayers();
	vector<Player> GetDefaultHeroes();
	vector<Player> GetDefaultVillains();
	void PrintCharacterInfo();
private:
	vector<Player> characters;
};

#endif // PLAYERS_LIST_H //