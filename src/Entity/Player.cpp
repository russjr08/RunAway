#include "Player.h"

sf::RectangleShape shape(sf::Vector2f(120, 50));

void Entity::update(){
    Game::debug("PLAYER UPDATE");
}

void Entity::render(sf::RenderTarget* window){
    shape.setFillColor(sf::Color::Red);
    window->draw(shape);
}
