#ifndef COMPONENT_H
#define COMPONENT_H

#include "../Game.hpp"
#include "../Entity/Entity.hpp"
#include <SFML/Graphics.hpp>

class Component {

public:
    void virtual render(sf::RenderTarget*, Entity*);
    void virtual update(float, Entity*);

};

#endif
