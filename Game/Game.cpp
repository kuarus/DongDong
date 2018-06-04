#include "Game.h"



Game::Game( ) {
}


Game::~Game( ) {
}

Game* Game::getInstance( ) {
	static Game* instance = new Game;
	return instance;
}


void Game::initialize( ) {
}

void Game::update( ) {
}

void Game::finalize( ) {
}