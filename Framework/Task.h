#pragma once

//�^�X�N�V�X�e���p�N���X
//���R���X�g���ł̏������֎~
//��������initialize( )  �I��������finalize( )
class Task {
public:
	Task( );
	virtual ~Task( );
public:
	//������
	virtual void initialize( ) = 0;
	//�X�V
	virtual void update( ) = 0;
	//�I������
	virtual void finalize( ) = 0;
};

