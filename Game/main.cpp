#include "Game.h"
#include "Framework.h"

void FwMain( ) {
	Framework* fw = Framework::getInstance( );
	Game* game = Game::getInstance( );
	fw->registerApp( game );
}