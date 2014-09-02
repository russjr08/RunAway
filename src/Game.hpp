#ifndef GAME_H
#define GAME_H

#include <iostream>

#include "SoundManager.hpp"
#include "ImageManager.hpp"

#include "Level/Level.hpp"

class Level;
class Game {
private:
    sf::Font roboto;
    sf::Font _minecraftia;
    static Game* instance;

    sf::View _view;

    Level* _level;

public:

    static constexpr bool DEBUGGING = true;


    static void debug(std::string msg){
        if(Game::DEBUGGING) {
            std::cout << "[DEBUG] " << msg << std::endl;
        }
    }

    static void error(std::string msg){
        std::cout << "[ERROR] " << msg << std::endl;
    }

    static Game* getInstance() { return instance; }

    sf::View& getView();

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
