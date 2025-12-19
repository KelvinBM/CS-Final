#include "Intro.h"
#include <chrono>
#include <thread>
#include "Players.h"

void Intro::GameIntroduction() {
    string name;
    cout << "Hello Player this game is a...." << /* game description and other stuff */ endl;
    cout << "What would you like to be called" << endl;
    getline(cin, name);
    cout << "Ok " << name << " here are the classes you can choose from" << endl;
    this_thread::sleep_for(chrono::seconds(2));// google
}
