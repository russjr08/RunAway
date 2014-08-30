#include "ImageManager.hpp"
#include "Game.hpp"
#include <map>

map<string, sf::Texture> textures;

void ImageManager::addTexture(string key, string file){
	Game::debug("[ImageManager] Registering: " + key + " -> " + file);
	textures[key] = sf::Texture();
	textures[key].loadFromFile(file);
}

sf::Texture ImageManager::getImage(string key){
	return textures[key];
}
