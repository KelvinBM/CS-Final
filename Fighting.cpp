// Fighting.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Attack.h"
#include "Player.h"
#include "Game.h"
#include "Players.h"
#include "Intro.h"
using namespace std;
int main() {

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

        Prologue(playerName);
        Player customPlayer = Player(playerName, 100, 8, 0, 0);
        cout << "Before you start your adventure what would you like to be called?" << endl;
        this_thread::sleep_for(chrono::seconds(1));
        string playerName;
        cin >> playerName;
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

            customAttacks.AssignAttack("Spark Slash", 12, 4);
            customAttacks.AssignAttack("Chain Lightning", 18, "A bolt that arcs to multiple foes", 5);
            customAttacks.AssignAttack("Thunder Nova", 25, "A burst of storm energy around the wielder", 6);

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
            customAttacks.AssignAttack("Gale Dance", 15, "A flurry of dagger strikes", 5);
            customAttacks.AssignAttack("Tempest Rush", 22, "Dash through an enemy with great speed", 6);

            customPlayer.AssignPlayerAttacks(customAttacks);

            cout << endl << "NEW MOVES" << endl;
            cout << "\t  1) Default Attack" << endl;
            cout << "\t  - Damage: " << customPlayer.GetAttackDamage();
            customPlayer.ShowAttacksInfo();
        }


    }



    return 0;
};
