#include "Game.h"
#include <iostream>
#include <random>
#include <ctime>
#include <chrono>
#include <thread>

Game::Game() {
	Players defaults = Players();
	heroes = defaults.GetDefaultHeroes();
	villains = defaults.GetDefaultVillains();

	rounds = 4;
}

Game::Game(vector<Player> heroesList, vector<Player> villainsList, int fightingRounds) {
	heroes = heroesList;
	villains = villainsList;
	rounds = fightingRounds;
}

void Game::FightingScenario1() {

}

void Game::PlayGame() {
	Players Choices;
	vector<Player> heroesList = Choices.GetDefaultHeroes();
	vector<Player> villainsList = Choices.GetDefaultVillains();

	cout << "Choose your hero by number:" << endl;
	for (int i = 0; i < heroesList.size() - 1; ++i) {
		cout << i << ") ";
		heroesList.at(i).ShowPlayerInfo();
	}

	int choice = 0;
	cout << "Enter number: ";
	cin >> choice;

	Player player = heroesList.at(choice);

	srand(time(NULL)); //google
	int villianChoice = rand() % villainsList.size();
	Player enemy = villainsList.at(villianChoice);

	cout << "Matchup: " << player.GetName() << " vs " << enemy.GetName() << endl;

	while (player.GetHealth() > 0 && enemy.GetHealth() > 0) {
		cout << "Your Health: " << player.GetHealth() << "  Enemy Health: " << enemy.GetHealth() << endl;
		cout << "Choose action: \n 1) Attack \n 2) Do nothing(other options soon)" << endl;
		int action;
		cin >> action;
		if (action == 1) {
			int dmg = player.GetAttackDamage();
			this_thread::sleep_for(chrono::seconds(1));
			cout << "You attack and deal " << dmg << " damage." << endl;
			enemy.TakeDamage(dmg);
		} else {
			this_thread::sleep_for(chrono::seconds(1));
			cout << "You do nothing" << endl;
		}

		if (enemy.GetHealth() <= 0) break;

		int enemyDmg;
			enemyDmg = rand() % (enemy.GetAttackDamage() + 1);
		cout << "Enemy attacks and deals " << enemyDmg << " damage" << endl;
		player.TakeDamage(enemyDmg);
	}
	if (player.GetHealth() <= 0) {
		cout << "You died. Game over." << endl;
	} else {
		cout << "You Defeated The Enemy." << endl;
	}
}