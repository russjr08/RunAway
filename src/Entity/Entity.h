#ifndef ENTITY_H
#define ENTITY_H

#include "../Game.h"
#include <SFML/Graphics.hpp>

class Entity {

public:

    virtual void render(sf::RenderTarget* window);
    virtual void update();

};


#endif
