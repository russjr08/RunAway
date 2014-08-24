
#include "SoundManager.h"
#include <map>

using namespace std;

map<string, sf::Sound*> game_audio;
map<string, sf::SoundBuffer> audio_src;

std::map<string, sf::Music*> game_music;

void SoundManager::addSound(string name, string file){
	game_audio[name] = new sf::Sound;
	audio_src[name] = sf::SoundBuffer();
	audio_src[name].loadFromFile(file);
	game_audio[name]->setBuffer(audio_src[name]);

}

void SoundManager::addMusic(string name, string file){
	game_music[name] = new sf::Music;
	game_music[name]->openFromFile(file);
}

sf::Sound* SoundManager::getSound(string name){
	return game_audio[name];
}

sf::Music* SoundManager::getMusic(string name){
	return game_music[name];
}

void SoundManager::playSound(string name){
	game_audio[name]->play();
}

void SoundManager::playMusic(string name){
	game_music[name]->play();
}
