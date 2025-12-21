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
	srand(time(0));
	enemySpares = rand() % 2; //  0  OR 1  //
	this_thread::sleep_for(chrono::seconds(1));
	//enemyPleads = rand() % 2;
	//cout << enemySpares << endl;

	Intro();

	SpaceMax();

	RunTheFights();

	SpaceMax();

	if (chosenPlayer.GetHealth() <= 0) {
		WriteSentenceNoEndl("You died. Game Over.");
		cout << endl;
	}
	else if (enemy.GetHealth() <= 0) {
		WriteSentenceNoEndl("You Defeated The Enemy.");
		cout << endl;
	}
	else if ( (youSpare && enemyPleads) || (youPlead && enemySpares) ) {
		WriteSentenceNoEndl("The battle only brought about the realization that conflict was never necessary,");
		cout << endl;
		WriteSentenceNoEndl("only the result of evil intents and lack of understanding.");
		cout << endl;
	}
	else if ( (youSpare && !enemyPleads) || (enemyPleads && !youSpare)) {
		WriteSentenceNoEndl("...Not the best ending I'd say.");
		cout << endl;
	}
	cout << endl << endl << endl << endl;
	cout << endl << endl << endl << endl;
}

void Game::Intro() {
	srand(time(0));
	cout << "Choose your hero by number:" << endl;

	//this_thread::sleep_for(chrono::seconds(2));
	cout << "------------------------" << endl;
	//this_thread::sleep_for(chrono::seconds(2));
	cout << endl;

	for (int i = 0; i < heroes.size() - 1; ++i) {// this allows us to not show the hidden characters

		cout << "\t\t   { " << i << " }";
		heroes.at(i).ShowPlayerInfo();
		this_thread::sleep_for(chrono::seconds(1));
		cout << "------";
		this_thread::sleep_for(chrono::seconds(1));
		cout << "------------";
		this_thread::sleep_for(chrono::seconds(1));
		cout << "------" << endl;
	}

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


<<<<<<< HEAD
	int villianChoice = rand() % villains.size();
	enemy = villains.at(villianChoice);
	//enemy = villains.at(0);// for testing
=======
	int villianChoice = rand() % villains.size() + 1;
	enemy = villains.at(villianChoice);
>>>>>>> 4f2f7dbb378e4e0a1495d741a3abbef69a9d8749

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
}

void Game::RunTheFights() {
	while (chosenPlayer.GetHealth() > 0 && enemy.GetHealth() > 0) {

		if (youPlead && enemySpares && chosenPlayer.GetHealth() <= 15) {
			break;
		}
		if (enemyPleads && youSpare && enemy.GetHealth() <= 15) {
			break;
		}

		TimeToAttack();
		if (enemy.GetHealth() <= 0) break;
		if (enemy.GetHealth() <= 15) {
			enemyPleads = true;
			enemy.GetCharacterAttacks().AssignAttack("Plead", 0, "Maybe he'll let me live", chosenPlayer.GetTotalAttacksCount() + 1); // makes a new attack
		}


		EnemyAttacks();
		if (chosenPlayer.GetHealth() <= 0) break;
		if (chosenPlayer.GetHealth() <= 15) {
			chosenPlayer.GetCharacterAttacks().AssignAttack("* Plead *", 0, "Maybe I'll survive this at least", chosenPlayer.GetTotalAttacksCount() + 1); // makes a new attack
		}

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

	cout << "    Available actions" << endl << endl;
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

		cout << "You attack them with your basic attack and deal " << heroDmg << " damage to " << enemy.GetName() << " " << endl;
		enemy.TakeDamage(heroDmg);

		cout << endl;
		cout << "Now " << enemy.GetName() << " has " << enemy.GetHealth() << " health left" << endl;

	}
	else if (actionChoice > 1) {
		Attack chosenAttack;

		chosenAttack = chosenPlayer.GetChosenAttack(actionChoice);
		heroDmg = chosenAttack.GetAttackDamage();

		Waiting();
		cout << endl << endl;

		if (actionChoice == 2) {
			//cout << "You run away to recuperate some health" << endl;
			cout << "You run away" << endl;
			chosenPlayer.HealUp((rand() % 10) + 5);
			//cout << "Your health is now at " << chosenPlayer.GetHealth() << endl;
		}
		else if (enemyPleads && enemy.GetHealth() <= 15) {
			if (youSpare) {
				cout << endl;
				this_thread::sleep_for(chrono::seconds(2));
				cout << "You tell" << enemy.GetName() << ", 'Don't worry, it was never that serious to begin with'" << endl;
			}
			else {
				cout << endl;
				this_thread::sleep_for(chrono::seconds(2));
				cout << "You say to" << enemy.GetName() << ", 'Really bruh'" << endl;
			}
		}
		else {
			if (actionChoice == chosenPlayer.GetTotalAttacksCount() && chosenPlayer.GetHealth() <= 15) {
				this_thread::sleep_for(chrono::seconds(2));
				cout << "You plead to " << enemy.GetName() << " hoping for a second chance at life." << endl;
				youPlead = true;
			}
			else {
				this_thread::sleep_for(chrono::seconds(2));
				cout << "You do the " << chosenAttack.GetAttackName() << " -> " << chosenAttack.GetAttackDesc() << " attack and deal " << heroDmg << " damage to " << enemy.GetName() << " " << endl;
				enemy.TakeDamage(heroDmg);

				cout << endl;
				this_thread::sleep_for(chrono::seconds(2));
				cout << "Now " << enemy.GetName() << " has " << enemy.GetHealth() << " health left" << endl;
			}
		}

		if (enemy.GetHealth() <= 20 && enemy.GetHealth() > 15) {
			EnemyInDisdainLevel1();
		}
		else if (enemy.GetHealth() <= 15 && enemy.GetHealth() >= 5) {
			enemyPleads = true;
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
	int randAttackChoice = rand() % numAttacks;
	int enemyDmg;
	if (!enemyPleads) {
		if (randAttackChoice == 1) {
			enemyDmg = enemy.GetAttackDamage();
			cout << "Enemy hits you with their default and deals " << enemyDmg << " damage" << endl;
		}
		else {
			Attack enemyAttack;

			enemyAttack = enemy.GetChosenAttack(randAttackChoice);
			enemyDmg = enemyAttack.GetAttackDamage();

			if (randAttackChoice == 2) {
				//cout << enemy.GetName() << " runs from you to recuperate some health " << endl;
				cout << enemy.GetName() << " runs..." << endl;
				enemy.HealUp((rand() % 10) + 10);
				//cout << "Their health is now at " << enemy.GetHealth() << endl;
			}
			else {
				if (randAttackChoice == enemy.GetTotalAttacksCount() && enemy.GetHealth() <= 15) {
					enemyPleads = true;
					cout << enemy.GetName() << " pleads to you, " << chosenPlayer.GetName() << ", to end the fight." << endl;
					this_thread::sleep_for(chrono::seconds(2));
				}
				else if (youPlead && chosenPlayer.GetHealth() <= 15) {
					if (enemySpares) {
						cout << endl;
						cout << enemy.GetName() << " spares you and says: 'I never intended to kill you in the first place'" << endl;
						this_thread::sleep_for(chrono::seconds(2));
					}
					else {
						cout << endl;
						cout << enemy.GetName() << " says: 'WOMP WOMP...'" << endl;
						this_thread::sleep_for(chrono::seconds(2));
					}
				}
				else {
					cout << enemy.GetName() << " attacks you with the " << enemyAttack.GetAttackName() << " -> " << enemyAttack.GetAttackDesc() << " attack and deals " << enemyDmg << " damage" << endl;
				}
			}

		}

		//enemyDmg = rand() % (enemy.GetAttackDamage() + 1);
		chosenPlayer.TakeDamage(enemyDmg);
	}
	else if (enemyPleads && youSpare) {
		cout << endl << endl << endl;
		cout << endl << endl << endl;
		cout << enemy.GetName() << " Pleads to you and you spare them" << endl;
		cout << endl;
		this_thread::sleep_for(chrono::seconds(2));
		cout << endl;
		cout << endl;
		cout << "You decide to spare who was once considered your enemy" << endl;
		cout << endl;
		this_thread::sleep_for(chrono::seconds(2));
		cout << endl;
		cout << "    * " << enemy.GetName() << " Is forever grateful for your mercy" << endl;
		this_thread::sleep_for(chrono::seconds(3));
	}
	else if (enemyPleads && !youSpare) {
		cout << endl << endl << endl;
		cout << endl << endl << endl;
		cout << enemy.GetName() << " falls down and cries" << endl;
		this_thread::sleep_for(chrono::seconds(2));
	}


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
	this_thread::sleep_for(chrono::seconds(1));
	cout << endl;
	cout << endl;
	cout << "   * " << enemy.GetName() << " Is losing enough health to question the fight" << endl;
	this_thread::sleep_for(chrono::seconds(3));

}

void Game::EnemyInDisdainLevel2() {
	this_thread::sleep_for(chrono::seconds(1));
	cout << endl;
	cout << "   * " << enemy.GetName() << " says he gives up. WILL YOU SPARE HIM???" << endl;
	cout << endl;
	this_thread::sleep_for(chrono::seconds(3));
	cout << "YES (1), NO (0): ";

	int decision;
	cin >> decision;
	youSpare = decision;
}

void Game::WriteSentenceNoEndl(string sentence) {
	for (int i = 0; i < sentence.size(); i++) {
		cout << sentence.at(i);

		if (i % 21 == 0) {
			this_thread::sleep_for(chrono::milliseconds(700));
		}
		else {
			this_thread::sleep_for(chrono::milliseconds(150));
		}
	}
}
