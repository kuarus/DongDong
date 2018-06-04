#pragma once
#include "Task.h"

class RenderingManager : public Task {
public:
	RenderingManager( );
	virtual ~RenderingManager( );
public:
	static RenderingManager* getInstance( );
public:
	void flip( );
	void drawObject2D( ) const;
	void drawObject3D( ) const;
private:
	virtual void initialize( ) override;
	virtual void update( )     override;
	virtual void finalize( )   override;
};

