#ifndef GAME_H
#define GAME_H

#include <iostream>

class Game {

public:

    static void debug(std::string msg){
        std::cout << "[DEBUG] " << msg << std::endl;
    }


};

#endif
