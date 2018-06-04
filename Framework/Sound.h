#pragma once
#include "Task.h"
class Sound : public Task {
private:
	Sound( );
	virtual ~Sound( );
public:
	static Sound* getInstance( );
private:
	virtual void initialize( ) override;
	virtual void update( )     override;
	virtual void finalize( )   override;
};

