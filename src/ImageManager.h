#ifndef IMAGEMANAGER_H
#define IMAGEMANAGER_H

#include <SFML/Graphics.hpp>
#include <string>

using namespace std;

class ImageManager {
public:
	void addTexture(string, string);

	sf::Texture* getImage(string);


};

#endif /* IMAGEMANAGER_H */
