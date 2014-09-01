#ifndef ENTITY_H
#define ENTITY_H

#include "../Game.hpp"
#include "../Component/Component.hpp"
#include "../Level/Level.hpp"
#include <vector>
#include <SFML/Graphics.hpp>

class Component;
class Entity {
protected:
    Game* game;
    sf::Vector2f pos;
    std::vector<Component *> components;

    Level* _level;

public:
    Entity(Game* game, Level* level) {
         this->game = game;
         this->_level = level;
    }

    virtual void render(sf::RenderTarget*);
    virtual void update(float);

};


#endif
