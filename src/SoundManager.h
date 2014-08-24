#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H

#include <SFML/Audio.hpp>
#include <iostream>

using namespace std;

// A class for managing sounds. See SoundManager.cpp for implementation details.
class SoundManager{
public:

	// Most of these methods are pretty self-explanatory...

	// Parameters: "Key" of the sound/music, and file path.
	void addSound(string, string);
	void addMusic(string, string);

	// Returns the pointer value to the respective sound/Music "Key"
	sf::Sound* getSound(string);
	sf::Music* getMusic(string);

	// Quick utility functions for playing sounds/Music. Params: "Key" of the audio
	void playSound(string);
	void playMusic(string);

	// Check the implementation for more details on this function. (SoundManager.cpp)
	void disposeAudio(string);



};

#endif /* SOUNDMANAGER_H */
