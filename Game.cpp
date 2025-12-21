#include "Game.h"
#include <iostream>
#include <random>
#include <ctime>
#include <chrono>
#include <thread>

Game::Game() {
	srand(time(0));
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

	// Intro(); //

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
	if (choice > heroes.size()-1 || choice < 0) {
		cout << "Invalid choice, choosing random hero for you..." << endl;
		choice = rand() % (heroes.size() - 1);
	}

	cout << endl << endl << endl << endl << endl;
	cout << endl << endl << endl << endl << endl;
	cout << endl << endl << endl << endl << endl;
	cout << endl << endl << endl << endl << endl;
	cout << endl << endl << endl << endl << endl;

	chosenPlayer = heroes.at(choice);


	int villianChoice = rand() % villains.size() + 1;
	enemy = villains.at(villianChoice);

	cout << endl << endl << endl << endl << endl;
	cout << endl << endl << endl << endl << endl;
	cout << endl << endl << endl << endl << endl;
	cout << endl << endl << endl << endl << endl;
	cout << endl << endl << endl << endl << endl;

	// MODIFY : ADD SCENARIO HERE : BEFORE FIGHTING //
	// BeforeFightEscenario(); // story before fighting

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
	cout << endl << endl;
	
	this_thread::sleep_for(chrono::seconds(3));

	SpaceMax();

	RunTheFights();
}

void Game::RunTheFights() {
	while (chosenPlayer.GetHealth() > 0 && enemy.GetHealth() > 0) {

		TimeToAttack();
		if (enemy.GetHealth() <= 0) break;

		EnemyAttacks();
		if (chosenPlayer.GetHealth() <= 0) break;

	}
	if (chosenPlayer.GetHealth() <= 0) {
		cout << "You died. Game Over." << endl;
	}
	else {
		cout << "You Defeated The Enemy." << endl;
	}
}

void Game::TimeToAttack() {
	cout << "-----------------------------------------------------------------------------" << endl;
	cout << "\t     |  Your Health: " << chosenPlayer.GetHealth() << "  ||  " << enemy.GetName() << "'s Health: " << enemy.GetHealth() << "  | " << endl; //" | Round: " << endl;
	cout << "-----------------------------------------------------------------------------" << endl;
	cout << endl;

	this_thread::sleep_for(chrono::seconds(1));

	cout << endl;
	cout << "    *[ It's your turn to attack, pick one of your available actions ]*" << endl;
	cout << endl << endl;
	this_thread::sleep_for(chrono::seconds(2));

	cout << "   Available actions" << endl << endl;
	cout << "\t  1) Default Attack" << endl; // "\n 2) Do nothing(other options soon)" << endl;
	cout << "\t  - Damage: " << chosenPlayer.GetAttackDamage();
	// attacks to choose from //
	chosenPlayer.ShowAttacksInfo();

	int actionChoice;
	cout << "Your selection: ";
	cin >> actionChoice;


	int heroDmg;
	if (actionChoice == 1) {
		heroDmg = chosenPlayer.GetAttackDamage();
		Waiting();

		cout << "You attack and deal " << heroDmg << " damage to " << enemy.GetName() << " " << endl;
		enemy.TakeDamage(heroDmg);
		cout << "Now " << enemy.GetName() << " has " << enemy.GetHealth() << " health left" << endl;

	}
	else if (actionChoice > 1) {
		heroDmg = chosenPlayer.GetChosenAttack(actionChoice).GetAttackDamage();
		Waiting();
		cout << endl << endl;
		cout << "You attack and deal " << heroDmg << " damage to " << enemy.GetName() << " " << endl;
		enemy.TakeDamage(heroDmg);
		cout << "Now " << enemy.GetName() << " has " << enemy.GetHealth() << " health left" << endl;

		if (enemy.GetHealth() <= 15 && enemy.GetHealth() >= 5) {
			EnemyInDisdainLevel1();
		}
		else if (enemy.GetHealth() <= 5) {
			EnemyInDisdainLevel2();
		}

	}
	else {
		this_thread::sleep_for(chrono::seconds(1));
		cout << "You do nothing" << endl;
	}
	cout << endl;
	cout << endl;
	Waiting();
	cout << endl;
	cout << endl;
}

void Game::EnemyAttacks() {
	int numAttacks = enemy.GetCharacterAttacks().GetNumAttacks();
	int randAttackChoice = rand() % numAttacks + 1;
	int enemyDmg;

	if (randAttackChoice == 1) {
		enemyDmg = enemy.GetAttackDamage();
	}
	else {
		enemyDmg = enemy.GetChosenAttack(randAttackChoice).GetAttackDamage();
	}


	//enemyDmg = rand() % (enemy.GetAttackDamage() + 1);
	cout << "Enemy attacks and deals " << enemyDmg << " damage" << endl;
	chosenPlayer.TakeDamage(enemyDmg);

	cout << endl;
	cout << endl;
	Waiting();
	cout << endl;
	cout << endl;
}

void Game::Waiting() {
	cout << endl;
	this_thread::sleep_for(chrono::seconds(1));
	cout << "..";
	this_thread::sleep_for(chrono::seconds(1));
	cout << "..";
	this_thread::sleep_for(chrono::seconds(1));
	cout << "..";
	cout << endl << endl;
}

void Game::SpaceMax() {
	cout << endl << endl << endl << endl << endl;
	cout << endl << endl << endl << endl << endl;
	cout << endl << endl << endl << endl << endl;
	cout << endl << endl << endl << endl << endl;
	cout << endl << endl << endl << endl << endl;
	cout << endl << endl << endl << endl << endl;
}

void Game::EnemyInDisdainLevel1() {
	cout << "   *" << enemy.GetName() << " Is now soo low in health that fear is the only thing it feels." << endl;
	cout << endl;
}

void Game::EnemyInDisdainLevel2() {
	cout << "   *" << enemy.GetName() << " says he gives up. WILL YOU SPARE HIM???" << endl;
	cout << endl;
}