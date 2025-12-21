#include "Game.h"
#include <iostream>
#include <random>
#include <ctime>
#include <chrono>
#include <thread>

using namespace std;

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
	cout << "Choose your hero by number" << endl;

	this_thread::sleep_for(chrono::seconds(3));
	cout << "---------------------------" << endl;
	this_thread::sleep_for(chrono::seconds(1));
	cout << endl;

	for (int i = 0; i < heroes.size() - 1; ++i) {// this allows us to not show the hidden characters

		cout << "\t\t   { " << i << " }";
		heroes.at(i).ShowPlayerInfo();
		this_thread::sleep_for(chrono::seconds(1));
		cout << "---------";
		this_thread::sleep_for(chrono::seconds(1));
		cout << "------------";
		this_thread::sleep_for(chrono::seconds(1));
		cout << "------" << endl;
		this_thread::sleep_for(chrono::seconds(2));

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


	int villianChoice = rand() % villains.size();
	enemy = villains.at(villianChoice);
	//enemy = villains.at(0);// for testing

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
	
	this_thread::sleep_for(chrono::seconds(6));
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
			this_thread::sleep_for(chrono::seconds(3));
		}


		EnemyAttacks();
		if (chosenPlayer.GetHealth() <= 0) break;
		if (chosenPlayer.GetHealth() <= 15) {
			SpaceMed();

			cout << "'Will you plead for your life?'" << endl;
			this_thread::sleep_for(chrono::seconds(4));
			WriteSentenceNoEndl("Enter (1) - Yes or (0) - No: ");

			int decision;
			cin >> decision;

			SpaceMax();
			if (decision == 1) {
				chosenPlayer.GetCharacterAttacks().AssignAttack("* Plead *", 0, "Maybe I'll survive this at least", chosenPlayer.GetTotalAttacksCount() + 1); // makes a new attack
			}
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
	this_thread::sleep_for(chrono::seconds(3));

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
		this_thread::sleep_for(chrono::seconds(4));

		cout << endl;
		cout << "Now " << enemy.GetName() << " has " << enemy.GetHealth() << " health left" << endl;
		this_thread::sleep_for(chrono::seconds(3));


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
			chosenPlayer.HealUp(rand() % 60);
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
				this_thread::sleep_for(chrono::seconds(1));
				cout << "You do the " << chosenAttack.GetAttackName() << " -> " << chosenAttack.GetAttackDesc() << " attack and deal " << heroDmg << " damage to " << enemy.GetName() << " " << endl;
				enemy.TakeDamage(heroDmg);

				cout << endl;
				this_thread::sleep_for(chrono::seconds(5));
				cout << "Now " << enemy.GetName() << " has " << enemy.GetHealth() << " health left" << endl;
			}
		}

		if (enemy.GetHealth() <= 20 && enemy.GetHealth() > 15) {
			EnemyInDisdainLevel1();
		}
		else if (enemy.GetHealth() <= 15 && enemy.GetHealth() >= 5) {
			//enemyPleads = rand() % 2;
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
			this_thread::sleep_for(chrono::seconds(4));
			cout << endl;

			chosenPlayer.TakeDamage(enemyDmg);
			cout << "You now have " << chosenPlayer.GetHealth() << " health left" << endl;
			this_thread::sleep_for(chrono::seconds(3));
		}
		else {
			Attack enemyAttack;

			enemyAttack = enemy.GetChosenAttack(randAttackChoice);
			enemyDmg = enemyAttack.GetAttackDamage();

			if (randAttackChoice == 2) {
				//cout << enemy.GetName() << " runs from you to recuperate some health " << endl;
				cout << enemy.GetName() << " runs..." << endl;
				enemy.HealUp(rand() % 100);
				//cout << "Their health is now at " << enemy.GetHealth() << endl;
			}
			else {
				if (randAttackChoice == enemy.GetTotalAttacksCount() && enemy.GetHealth() <= 15) {
					enemyPleads = true;
					cout << enemy.GetName() << " pleads to you, " << chosenPlayer.GetName() << ", to end the fight." << endl;
					this_thread::sleep_for(chrono::seconds(3));
				}
				else if (youPlead && chosenPlayer.GetHealth() <= 15) {
					if (enemySpares) {
						cout << endl;
						cout << enemy.GetName() << " spares you and says: '";
						WriteSentenceNoEndl("I never intended to kill you in the first place");
						cout << "'" << endl;
						this_thread::sleep_for(chrono::seconds(4));
					}
					else {
						cout << endl;
						cout << enemy.GetName() << " says: '";
						WriteSentenceNoEndl("WOMP WOMP...");
						cout << "'" << endl;

						this_thread::sleep_for(chrono::seconds(3));
					}
				}
				else {
					cout << enemy.GetName() << " attacks you with the " << enemyAttack.GetAttackName() << " -> " << enemyAttack.GetAttackDesc() << " attack and deals " << enemyDmg << " damage" << endl;
					this_thread::sleep_for(chrono::seconds(5));
					cout << endl;

					chosenPlayer.TakeDamage(enemyDmg);
					cout << "Now you have " << chosenPlayer.GetHealth() << " health left" << endl;
					this_thread::sleep_for(chrono::seconds(3));

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
		this_thread::sleep_for(chrono::seconds(4));
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

void Game::SpaceMed() {
	cout << endl << endl << endl << endl << endl;
	cout << endl << endl << endl << endl << endl;
	cout << endl << endl << endl << endl << endl;
	cout << endl << endl << endl << endl << endl;
	cout << endl << endl << endl << endl << endl;
	cout << endl << endl;
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
	if (decision == 0 || decision == 1) {
		youSpare = decision;
	}
	else {
		youSpare = true;
	}
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

void Game::StoryModeFight(Player PlayerCharacter, Player EnemyChar) {
	cout << "Starting fight between " << PlayerCharacter.GetName() << " and " << EnemyChar.GetName() << "\n";
	bool playersTurn = true;
	while (PlayerCharacter.GetHealth() > 0 && EnemyChar.GetHealth() > 0) {
		cout << "---------------------------------------------\n";
		cout << PlayerCharacter.GetName() << " HP: " << PlayerCharacter.GetHealth() << "  |  " << EnemyChar.GetName() << " HP: " << EnemyChar.GetHealth() << "\n";
		cout << "---------------------------------------------\n";

		if (playersTurn) {
			cout << "It's " << PlayerCharacter.GetName() << "'s turn.\n";
			cout << "1) Default attack (damage: " << PlayerCharacter.GetAttackDamage() << ")\n";
			PlayerCharacter.ShowAttacksInfo();
			int choice = 1;
			cout << "Choose action (enter number, default 1): ";
			cin >> choice;

			if (choice <= 1) {
				int dmg = PlayerCharacter.GetAttackDamage();
				cout << PlayerCharacter.GetName() << " deals " << dmg << " damage to " << EnemyChar.GetName() << "\n";
				EnemyChar.TakeDamage(dmg);
			}
			else {
				Attack atk = PlayerCharacter.GetChosenAttack(choice);
				int dmg = atk.GetAttackDamage();
				cout << PlayerCharacter.GetName() << " uses " << atk.GetAttackName() << " and deals " << dmg << " damage\n";
				EnemyChar.TakeDamage(dmg);
			}
		}
		else {
			cout << "It's " << EnemyChar.GetName() << "'s turn.\n";
			int numAtk = EnemyChar.GetTotalAttacksCount();
			int choice = 1;
			if (numAtk > 1) choice = (rand() % numAtk) + 1;
			if (choice <= 1) {
				int dmg = EnemyChar.GetAttackDamage();
				cout << EnemyChar.GetName() << " deals " << dmg << " damage to " << PlayerCharacter.GetName() << "\n";
				PlayerCharacter.TakeDamage(dmg);
			}
			else {
				Attack atk = EnemyChar.GetChosenAttack(choice);
				int dmg = atk.GetAttackDamage();
				cout << EnemyChar.GetName() << " uses " << atk.GetAttackName() << " and deals " << dmg << " damage\n";
				PlayerCharacter.TakeDamage(dmg);
			}
		}

		playersTurn = !playersTurn;
		this_thread::sleep_for(chrono::seconds(1));
	}

	cout << "\nFight ended.\n";
	if (PlayerCharacter.GetHealth() <= 0) {
		cout << PlayerCharacter.GetName() << " has been defeated.\n";
	}
	if (EnemyChar.GetHealth() <= 0) {
		cout << EnemyChar.GetName() << " has been defeated.\n";
	}
	cout << "\n";
}
