#include "Players.h"
#include <chrono>
#include <thread>


vector<Player> Players::GetDefaultHeroes() { // only need to call once
	Attack runAway = Attack();// default attack // assigned (2)
	Attack punch = Attack("Punch", 5, 3); // assigend (3)


	// -------------------------------------------------------------------------------------------- //
	Player defaultHero = Player();
	Attacks defaultAttacks;
	defaultAttacks.AssignAttack(runAway);// 2
	defaultAttacks.AssignAttack(punch);// 3
	defaultAttacks.AssignAttack("Pickaxe", 20, 4);// 4
	defaultHero.AssignPlayerAttacks(defaultAttacks);


	// -------------------------------------------------------------------------------------------- //
	Player destroyer = Player("Destroyer of Ankles", 150, 20, 3, 1);
	Attacks destroyerAttacks;
	destroyerAttacks.AssignAttack(runAway);// 2
	destroyerAttacks.AssignAttack(punch);// 3
	destroyerAttacks.AssignAttack("Crossover", 15, "Get yo ankles broke lil' boy", 4);// 4
	destroyer.AssignPlayerAttacks(destroyerAttacks);


	// -------------------------------------------------------------------------------------------- //
	Player valiant = Player("Valiant Hero", 95, 12, 0, 2);
	Attacks valiantAttacks;
	valiantAttacks.AssignAttack(runAway);// 2
	valiantAttacks.AssignAttack(punch);// 3
	valiantAttacks.AssignAttack("Undefeated", 25, "Fight with all your might", 4);// 4
	valiant.AssignPlayerAttacks(valiantAttacks);


	// -------------------------------------------------------------------------------------------- //
	Player vagabond = Player("Vagabond", 120, 13, 2, 3);
	Attacks vagabondAttacks;
	vagabondAttacks.AssignAttack(runAway);// 2
	vagabondAttacks.AssignAttack(punch);// 3
	vagabondAttacks.AssignAttack("Eminent Shadow", 26, "...", 4);// 4
	vagabond.AssignPlayerAttacks(vagabondAttacks);


	// -------------------------------------------------------------------------------------------- //
	Player ratatouie = Player("Ratatouie", 85, 15, 0, 4);
	Attacks ratatouieAttacks;
	ratatouieAttacks.AssignAttack(runAway);// 2
	ratatouieAttacks.AssignAttack(punch);// 3
	ratatouieAttacks.AssignAttack("Jugular", 22, "Uppercut to the jugular", 4);// 4
	ratatouie.AssignPlayerAttacks(ratatouieAttacks);


	// -------------------------------------------------------------------------------------------- //
	Player secret = Player("YOU WILL NOT SURVIVE", 1000000, 1000000, 0, -1); // cheat character // hidden from players in beginning // they must input random choice and might possibly get it
	Attacks secretAttacks;
	secretAttacks.AssignAttack(runAway);// 2
	secretAttacks.AssignAttack("THE END", 1000000000, "YOU ARE COOKED BUDDY", 3);// 2 since this character doesn't run away
	secret.AssignPlayerAttacks(secretAttacks);




	// -------------------------------------------------------------------------------------------- //
	vector<Player> players;
	players.push_back(defaultHero);
	players.push_back(destroyer);
	players.push_back(valiant);
	players.push_back(vagabond);
	players.push_back(ratatouie);
	players.push_back(secret);

	characters = players;
	return characters; // If you dont return here it basically just gets rid of the classes after its run, need to likely return for villians too
}

vector<Player> Players::GetDefaultVillains() { // only need to call once
	Attack runAway = Attack();// default attack // assigned (2)
	Attack punch = Attack("Punch", 7, 3);// assigned (3)

	// -------------------------------------------------------------------------------------------- //
	Player defaultVillain = Player("Regular Villain Guy", 110, 10, 0, 0);
	// attack types for defaultVillain are set through constructor default
	Attacks defaultAttacks;
	defaultAttacks.AssignAttack(runAway);// 2
	defaultAttacks.AssignAttack(punch);// 3
	defaultAttacks.AssignAttack("Another Punch", 20, "Just another of my regular punches", 4);// 4
	defaultVillain.AssignPlayerAttacks(defaultAttacks);

	// -------------------------------------------------------------------------------------------- //
	Player tickleMaster = Player("The Tickle Master", 120, 25, 1, 1); // buff build // long cooldown
	Attacks tickleMasterAttacks;
	tickleMasterAttacks.AssignAttack(runAway);// 2
	tickleMasterAttacks.AssignAttack(punch);// 3
	tickleMasterAttacks.AssignAttack("Tickle", 27, "...Maybe it's better to not say", 4);// 4
	tickleMaster.AssignPlayerAttacks(tickleMasterAttacks);


	// -------------------------------------------------------------------------------------------- //
	Player peppe = Player("Peppe", 105, 12, 0, 2);
	Attacks peppeAttacks;
	peppeAttacks.AssignAttack(runAway);// 2
	peppeAttacks.AssignAttack(punch);// 3
	peppeAttacks.AssignAttack("Uhh", 30, "Write a 100,000,000 word essay by tonight! (YOU GET FILLED WITH STRESS FROM THIS)", 4);// 4
	peppe.AssignPlayerAttacks(peppeAttacks);


	// -------------------------------------------------------------------------------------------- //
	Player python = Player("Python", 120, 13, 2, 3);
	Attacks pythonAttacks;
	pythonAttacks.AssignAttack(runAway);// 2
	pythonAttacks.AssignAttack(punch);// 3
	pythonAttacks.AssignAttack("Slither IO", 30, "Tries to eat you and chases you for a VERY VERY LONG TIME", 4);// 4
	python.AssignPlayerAttacks(pythonAttacks);


	// -------------------------------------------------------------------------------------------- //
	Player cocomelon = Player("Cocomelon", 185, 15, 1, 4);
	Attacks cocomelonAttacks;
	cocomelonAttacks.AssignAttack(runAway);// 2
	cocomelonAttacks.AssignAttack(punch);// 3
	cocomelonAttacks.AssignAttack("GooGoo GaGa", 400, "GooGoo GaGa ~~ Translation: Hope you don't get hit by this🥶👶", 4);// 4
	cocomelon.AssignPlayerAttacks(cocomelonAttacks);




	// -------------------------------------------------------------------------------------------- //
	vector<Player> players;
	players.push_back(defaultVillain);
	players.push_back(tickleMaster);
	players.push_back(peppe);
	players.push_back(python);
	players.push_back(cocomelon);

	characters = players;
	return characters;
}

vector<Player> Players::GetPlayers() {
	return characters;
}

void Players::PrintCharacterInfo() {
	for (int i = 0; i < characters.size() - 1; i++) {
		characters.at(i).ShowPlayerInfo();
		this_thread::sleep_for(chrono::seconds(2));
	}
}