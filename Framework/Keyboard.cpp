#include "Keyboard.h"


Keyboard::Keyboard( ) {
}


Keyboard::~Keyboard( ) {
}

Keyboard* Keyboard::getInstance( ) {
	static Keyboard* instance = new Keyboard;
	return instance;
}

void Keyboard::initialize( ) {
}

void Keyboard::update( ) {
}

void Keyboard::finalize( ) {
}