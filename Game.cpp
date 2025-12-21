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

Game::Game(int fightingRounds) {
	Players defaults = Players();
	heroes = defaults.GetDefaultHeroes();
	villains = defaults.GetDefaultVillains();

	rounds = fightingRounds;
}

Game::Game(vector<Player> heroesList, vector<Player> villainsList, int fightingRounds) {
	heroes = heroesList;
	villains = villainsList;
	rounds = fightingRounds;
}

void Game::FightingScenario1() {
	// MODIFY : STILL DECIDING IF INCLUDING SCENARIOS OR NOT //
}

void Game::PlayGame() {

	cout << "Choose your hero by number:" << endl;
	this_thread::sleep_for(chrono::seconds(2));

	for (int i = 0; i < heroes.size() - 1; ++i) {// this allows us to not show the hidden characters
		cout << "------------------------" << endl;
		cout << endl;

		cout << "\t\t   { " << i << " }";
		heroes.at(i).ShowPlayerInfo();
		this_thread::sleep_for(chrono::seconds(1));
	}
	cout << "------------------------" << endl;

	cout << endl << endl;

	int choice = 0;
	cout << "Enter Selection (number): ";
	cin >> choice;

	cout << endl << endl << endl << endl << endl;
	cout << endl << endl << endl << endl << endl;
	cout << endl << endl << endl << endl << endl;
	cout << endl << endl << endl << endl << endl;
	cout << endl << endl << endl << endl << endl;

	chosenPlayer = heroes.at(choice);


	srand(time(0));
	int villianChoice = rand() % villains.size();
	enemy = villains.at(villianChoice);

	cout << "...................................................." << endl;
	cout << endl;

	cout << "| YOUR CHOICE |" << endl;
	chosenPlayer.ShowPlayerInfo();

	cout << endl;

	cout << "  ~  ~  ~  ~  ~  ~  ~  ~  ~  ~  ~  ~  ~  ~  ~  ~" << endl;
	cout << endl;

	cout << "| MATCHUP |" << endl;
	enemy.ShowPlayerInfo();
	cout << endl;
	cout << "...................................................." << endl;
	cout << endl;
	
	this_thread::sleep_for(chrono::seconds(5));

	cout << endl << endl << endl << endl << endl;
	cout << endl << endl << endl << endl << endl;
	cout << endl << endl << endl << endl << endl;
	cout << endl << endl << endl << endl << endl;
	cout << endl << endl << endl << endl << endl;

	RunTheFights();
}

void Game::RunTheFights() {
	while (chosenPlayer.GetHealth() > 0 && enemy.GetHealth() > 0) {
		cout << "-----------------------------------------------------------" << endl;
		cout << "   Your Health: " << chosenPlayer.GetHealth() << " ||  Enemy Health: " << enemy.GetHealth() << " | " << endl;
		cout << "-----------------------------------------------------------" << endl;
		cout << endl;

		// attacks to choose from //
		chosenPlayer.ShowAttacksInfo();



		int action;
		cin >> action;
		if (action == 1) {
			int dmg = chosenPlayer.GetAttackDamage();
			this_thread::sleep_for(chrono::seconds(1));
			cout << "You attack and deal " << dmg << " damage." << endl;
			enemy.TakeDamage(dmg);
		}
		else {
			this_thread::sleep_for(chrono::seconds(1));
			cout << "You do nothing" << endl;
		}

		if (enemy.GetHealth() <= 0) break;

		int enemyDmg;
		enemyDmg = rand() % (enemy.GetAttackDamage() + 1);
		cout << "Enemy attacks and deals " << enemyDmg << " damage" << endl;
		chosenPlayer.TakeDamage(enemyDmg);
	}
	if (chosenPlayer.GetHealth() <= 0) {
		cout << "You died. Game over." << endl;
	}
	else {
		cout << "You Defeated The Enemy." << endl;
	}
}

void Game::TimeToAttack() {
	cout << endl;
	cout << "\t It's your turn to attack" << endl;

	cout << "\t Pick one of your available actions" << endl;
}