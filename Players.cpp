#include "Players.h"
#include <chrono>
#include <thread>


vector<Player> Players::GetDefaultHeroes() { // only need to call once
	Player defaultHero = Player();
	// attack types for the defaultHero are assigned through constructor


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
	players.push_back(defaultHero);
	players.push_back(destroyer);
	players.push_back(valiant);
	players.push_back(vagabond);
	players.push_back(minuscle);
	players.push_back(secret);

	characters = players;
	return characters; // If you dont return here it basically just gets rid of the classes after its run, need to likely return for villians too
}

vector<Player> Players::GetDefaultVillains() { // only need to call once
	Player defaultVillain = Player();
	// attack types for defaultVillain are set through constructor default


	Player tickleMaster = Player("The Tickle Master", 120, 1, 1, 2); // buff build // long cooldown
	// attack types for the tickleMaster


	Player valiant = Player("Valiant Hero", 95, 12, 0, 2); // doesn't do much damage, can avoid attacks, doesn't need cooldown as he pushes forward //
	// attack types for the destroyer


	Player vagabond = Player("Vagabond", 120, 13, 2, 3);
	// attack types for the destroyer


	Player minuscle = Player("Ratatouie", 85, 15, 0, 4); // feeds the enemy until the die (they have no choice but to eat when he does)
	// attack types for the destroyer


	Player secret = Player("YOU WILL NOT SURVIVE", 1000000, 10000, 0, 7); // cheat character // hidden from players in beginning // they must input random choice and might possibly get it
	// attack types for the destroyer



	vector<Player> players;
	players.push_back(defaultVillain);
	players.push_back(tickleMaster);
	players.push_back(valiant);
	players.push_back(vagabond);
	players.push_back(minuscle);
	players.push_back(secret);

	characters = players;
}

vector<Player> Players::GetPlayers() {
	return characters;
}

void Players::PrintCharacterInfo() {
	for (int i = 0; i < characters.size() - 1; i++) {
		characters.at(i).ShowPlayerInfo();
		this_thread::sleep_for(chrono::seconds(1));
	}
}


/*

	vector<Player> GetPlayers();
	void AssignPlayers();

*/