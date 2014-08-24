#ifndef GAME_H
#define GAME_H

#include <iostream>

#include "SoundManager.h"
#include "ImageManager.h"


class Game {

public:

    static void debug(std::string msg){
        std::cout << "[DEBUG] " << msg << std::endl;
    }

    static void error(std::string msg){
        std::cout << "[ERROR] " << msg << std::endl;
    }

    const static int WIDTH = 800, HEIGHT = 600;

    void open();
    void close();
    void render();
    void update(float);

    SoundManager sounds;
	ImageManager images;



};

#endif
