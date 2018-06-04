#include "Framework.h"
#include "Task.h"
#include "Keyboard.h"
#include "Sound.h"
#include "RenderingManager.h"

#include "DxLib.h"

Framework::Framework( ) :
m_windowmode( true ) {
}


Framework::~Framework( ) {
}

Framework* Framework::getInstance( ) {
	static Framework* instance = new Framework( );
	return instance;
}

//アプリ進行用タスク(自作タスク)を登録する
void Framework::registerApp( Task* app ) {
	m_tasks[ ( int )TASK::App ] = app;
}

//実行処理
void Framework::run( ) {
	initialize( );
	while ( isLoop( ) ) {
		update( );
	}
	finalize( );
}

//ループを続けるかどうか
bool Framework::isLoop( ) const {
	if ( ProcessMessage( ) != 0 ) {
		return false;
	}
	if ( CheckHitKey( KEY_INPUT_ESCAPE ) != 0 ) {
		return false;
	}
	return true;
}

//初期化処理
void Framework::initialize( ) {
	ChangeWindowMode( m_windowmode ? TRUE : FALSE );
	if ( DxLib_Init( ) == -1 ) {
		//ProcessMessageで-1が帰ってきて強制終了となる
		return;
	}
	m_tasks[ ( int )TASK::RenderingManager ] = RenderingManager::getInstance( );
	m_tasks[ ( int )TASK::Keyboard ] = Keyboard::getInstance( );
	m_tasks[ ( int )TASK::Sound ] = Sound::getInstance( );
}

//更新処理
void Framework::update( ) {
	for ( int i = 0; i < ( int )TASK::Max; i++ ) {
		m_tasks[ i ]->update( );
	}
}

//終了処理
void Framework::finalize( ) {
	for ( int i = 0; i < ( int )TASK::Max; i++ ) {
		m_tasks[ i ]->finalize( );
	}
	for ( int i = 0; i < ( int )TASK::Max; i++ ) {
		delete m_tasks[ i ];
	}
	DxLib_End( );
}