#include "Sound.h"


Sound::Sound( ) {
}


Sound::~Sound( ) {
}

Sound* Sound::getInstance( ) {
	static Sound* instance = new Sound;
	return instance;
}

void Sound::initialize( ) {
}

void Sound::update( ) {
}

void Sound::finalize( ) {
}