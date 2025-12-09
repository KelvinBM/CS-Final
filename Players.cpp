#include "Players.h"

void Players::PopulateList() { // only need to call once
	Player theDefault = Player();
	// attack types for theDefault


	Player destroyer = Player("Destroyer of Ankles", 150, 20, 3, 1); // buff build // long cooldown
	// attack types for the destroyer
	

	Player valiant = Player("Valiant Hero", 95, 12, 0, 2); // doesn't do much damage, can avoid attacks, doesn't need cooldown as he pushes forward //
	// attack types for the destroyer

	
	Player vagabond = Player("Vagabond", 120, 13, 2, 3);
	// attack types for the destroyer

	
	Player minuscle = Player("Ratatouie", 85, 15, 0, 4); // feeds the enemy until the die (they have no choice but to eat when he does)
	// attack types for the destroyer


	Player secret = Player("YOU WILL NOT SURVIVE", 1000000, 10000, 0, 7); // cheat character // hidden from players in beginning // they must input random choice and might possibly get it
	// attack types for the destroyer



	vector<Player> players;
	players.push_back(theDefault);
	players.push_back(destroyer);
	players.push_back(valiant);
	players.push_back(vagabond);
	players.push_back(minuscle);
	players.push_back(secret);


	characters = players;
}

vector<Player> Players::GetPlayers() {
	return characters;
}



/*

	vector<Player> GetPlayers();
	void AssignPlayers();

*/