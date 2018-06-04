#pragma once
#include "Task.h"

class Keyboard : public Task {
private:
	Keyboard( );
	virtual ~Keyboard( );
public:
	static Keyboard* getInstance( );
private:
	virtual void initialize( ) override;
	virtual void update( )     override;
	virtual void finalize( )   override;
};

