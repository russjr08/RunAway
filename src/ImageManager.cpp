#include "ImageManager.h"
#include <map>

map<string, sf::Texture> textures;

void ImageManager::addTexture(string key, string file){
	textures[key] = sf::Texture();
	textures[key].loadFromFile(file);
}

sf::Texture* ImageManager::getImage(string key){
	return &textures[key];
}
