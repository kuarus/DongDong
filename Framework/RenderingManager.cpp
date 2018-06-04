#include "RenderingManager.h"
#include "DxLib.h"

RenderingManager::RenderingManager( ) {
}


RenderingManager::~RenderingManager( ) {
}

RenderingManager* RenderingManager::getInstance( ) {
	static RenderingManager* instance = new RenderingManager;
	return instance;
}

void RenderingManager::initialize( ) {
	SetDrawScreen( DX_SCREEN_BACK );
}

void RenderingManager::update( ) {
}

void RenderingManager::finalize( ) {
}

void RenderingManager::flip( ) {
	ScreenFlip( );
	ClearDrawScreen( );
}

void RenderingManager::drawObject2D( ) const {
}

void RenderingManager::drawObject3D( ) const {
}