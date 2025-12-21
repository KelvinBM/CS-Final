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
    cout << "Which would you like to do \n 1. Fighting Mode \n 2. Story Mode" << endl;
    int modeChoice;
    cin >> modeChoice;
    if (modeChoice == 1) {
        bool playAgain = true;
        cout << "You have chosen Fighting Mode" << endl;
        Game fightingGame = Game();
        while (playAgain) {
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
        cout << "Before you start your adventure what would you like to be called?" << endl;
        string playerName;
        getline(cin, playerName);
        Prologue(playerName);
        Player customPlayer = Player(playerName, 100, 8, 0, 0);


    }



    return 0;
};
