#pragma once
#include "Task.h"

class Game : public Task {
private:
	Game( );
	virtual ~Game( );
public:
	static Game* getInstance( );
private:
	virtual void initialize( ) override;
	virtual void update( )     override;
	virtual void finalize( )   override;
};

