#include "Framework.h"

#include <Windows.h>

extern void FwMain( );

int WINAPI WinMain( HINSTANCE, HINSTANCE, LPSTR, int ) {
	Framework* fw = Framework::getInstance( ); 
	FwMain( );
	fw->run( );
	return 0;
}