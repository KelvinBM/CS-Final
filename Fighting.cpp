// Fighting.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "SwordArt.h"
#include <iostream>
#include "Attack.h"
#include "Player.h"
#include "Game.h"
#include "Players.h"
#include "Intro.h"
using namespace std;

int WorthinessScore = 0;
int main() {
    Game space;
    cout << "Hello Player this game is a turned based fighting game where you choose a hero and fight against villains." << endl;
    cout << "You can also play the story mode if you want more than just the fighting aspect." << endl;
    cout << endl;
    cout << endl;
    cout << "Which would you like to do \n\n 1. Fighting Mode \n 2. Story Mode" << endl;
    cout << endl;
    cout << "Enter choice number: ";

    int modeChoice;
    cin >> modeChoice;
    if (modeChoice == 1) {
        bool playAgain = true;
        Game fightingGame = Game();

        fightingGame.SpaceMax();
        cout << "You have chosen Fighting Mode" << endl;
        fightingGame.SpaceMed();

        this_thread::sleep_for(chrono::seconds(2));

        while (playAgain) {
            fightingGame.SpaceMed();
            fightingGame.PlayGame();
            cout << "Would you like to play again? (1 for yes, 2 for no)" << endl;
            int Replay;
            cin >> Replay;
            if (Replay == 1) {
                playAgain = true;
            }
            else {
                playAgain = false;
            }
        }
        return 0;
    }
    else if (modeChoice == 2) {
        cout << "You have chosen the Story Mode" << endl;
        cout << "Before you start your adventure what would you like to be called? " << endl;
        string playerName;
        getline(cin, playerName);

        int Choice;
        Choice = Prologue(playerName);
        Player customPlayer = Player(playerName, 100, 2, 0, 0);
        if (Choice == 1) {
            // Thunder Fang
            Attacks customAttacks;
            Attack runAway = Attack();
            Attack punch = Attack("Punch", 5, 3);
            customAttacks.AssignAttack(runAway);
            customAttacks.AssignAttack(punch);

            customAttacks.AssignAttack("Spark Slash", 12,"Chance to apply lighting damage(enemy takes 10 damage for 2 turns)", 4);
            customAttacks.AssignAttack("Chain Lightning", 18, "A bolt that arcs to multiple foes, chance to stun enemy", 5);
            customAttacks.AssignAttack("Thunder Nova", 25, "A burst of storm energy around the wielder, chance to parry/block enemies attack", 6);

            customPlayer.AssignPlayerAttacks(customAttacks);


            cout << endl << "NEW MOVES" << endl;
            cout << "\t  1) Default Attack" << endl;
            cout << "\t  - Damage: " << customPlayer.GetAttackDamage();
            customPlayer.ShowAttacksInfo();
        }
        else if (Choice == 2) {
            // Sky Piercers
            Attacks customAttacks;
            Attack runAway = Attack();
            Attack punch = Attack("Punch", 5, 3);
            customAttacks.AssignAttack(runAway);
            customAttacks.AssignAttack(punch);

            customAttacks.AssignAttack("Piercing Stab", 10, 4);
            customAttacks.AssignAttack("Lightning Overdriver", 15, "Plant your daggers into the floor channeling lightning through them (chance to damage yourself)", 5);
            customAttacks.AssignAttack("Shadow Step", 22, "Dash and disappear before striking the enemy from behind", 6);

            customPlayer.AssignPlayerAttacks(customAttacks);

            cout << endl << "NEW MOVES" << endl;
            cout << "\t  1) Default Attack" << endl;
            cout << "\t  - Damage: " << customPlayer.GetAttackDamage();
            customPlayer.ShowAttacksInfo();
        }
    cout << "Shadow Being: In order to prove your worthiness you must go through 3 trials that will test your skills" << endl;
    this_thread::sleep_for(chrono::seconds(2));
        cout << "To begin walk through that door" << endl;
        cout << "*The being bangs his staff on the ground again and a door materializes in front of you*" << endl;
        this_thread::sleep_for(chrono::seconds(2));
        space.SpaceMax();
        cout << "Trial One....";
    }



    return 0;
};
