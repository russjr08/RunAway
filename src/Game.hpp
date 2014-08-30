#ifndef GAME_H
#define GAME_H

#include <iostream>

#include "SoundManager.hpp"
#include "ImageManager.hpp"


class Game {
private:
    sf::Font roboto;
    static Game* instance;

public:

    static void debug(std::string msg){
        std::cout << "[DEBUG] " << msg << std::endl;
    }

    static void error(std::string msg){
        std::cout << "[ERROR] " << msg << std::endl;
    }

    static Game* getInstance() { return instance; }

    const static int WIDTH = 800, HEIGHT = 600;

    void open();
    void close();
    void render();
    void update(float);
    sf::Text getText(string, unsigned int size);

    SoundManager sounds;
	ImageManager images;



};

#endif
