#include "Game.h"

Game::Game() {
	Players herosAssigned = Players();
	Players villainsAssigned = Players();
	rounds = 4;
}

Game::Game(Players heroesList, Players villainsList, int fightingRounds = 4) {
	heroes = heroesList;
	villains = villainsList;
	rounds = fightingRounds;
}

void Game::FightingScenario1() {

}

void Game::PlayGame() {

}