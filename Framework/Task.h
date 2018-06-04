#pragma once

//タスクシステム用クラス
//※コンストラでの初期化禁止
//初期化はinitialize( )  終了処理はfinalize( )
class Task {
public:
	Task( );
	virtual ~Task( );
public:
	//初期化
	virtual void initialize( ) = 0;
	//更新
	virtual void update( ) = 0;
	//終了処理
	virtual void finalize( ) = 0;
};

