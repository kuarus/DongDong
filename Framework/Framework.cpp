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

//�A�v���i�s�p�^�X�N(����^�X�N)��o�^����
void Framework::registerApp( Task* app ) {
	m_tasks[ ( int )TASK::App ] = app;
}

//���s����
void Framework::run( ) {
	initialize( );
	while ( isLoop( ) ) {
		update( );
	}
	finalize( );
}

//���[�v�𑱂��邩�ǂ���
bool Framework::isLoop( ) const {
	if ( ProcessMessage( ) != 0 ) {
		return false;
	}
	if ( CheckHitKey( KEY_INPUT_ESCAPE ) != 0 ) {
		return false;
	}
	return true;
}

//����������
void Framework::initialize( ) {
	ChangeWindowMode( m_windowmode ? TRUE : FALSE );
	if ( DxLib_Init( ) == -1 ) {
		//ProcessMessage��-1���A���Ă��ċ����I���ƂȂ�
		return;
	}
	m_tasks[ ( int )TASK::RenderingManager ] = RenderingManager::getInstance( );
	m_tasks[ ( int )TASK::Keyboard ] = Keyboard::getInstance( );
	m_tasks[ ( int )TASK::Sound ] = Sound::getInstance( );
}

//�X�V����
void Framework::update( ) {
	for ( int i = 0; i < ( int )TASK::Max; i++ ) {
		m_tasks[ i ]->update( );
	}
}

//�I������
void Framework::finalize( ) {
	for ( int i = 0; i < ( int )TASK::Max; i++ ) {
		m_tasks[ i ]->finalize( );
	}
	for ( int i = 0; i < ( int )TASK::Max; i++ ) {
		delete m_tasks[ i ];
	}
	DxLib_End( );
}