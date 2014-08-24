#include <SFML/Graphics.hpp>

#include <map>

#include "Game.h"
#include "Entity/Player.h"

sf::RenderWindow window(sf::VideoMode(Game::WIDTH, Game::HEIGHT), "RunAway!");

sf::Clock deltaClock;

sf::CircleShape sun(50);

std::vector<Entity> entities;

int main(){

    Game game;
    game.open();

    return 0;

}

void Game::open(){

    entities.push_back(Player(this));

    window.setFramerateLimit(60);

    sun.setFillColor(sf::Color::Yellow);
    sun.setPosition(sf::Vector2f(Game::WIDTH - 100, 0));

    while(window.isOpen()){
    sf::Event event;
        while(window.pollEvent(event)){
            sf::Time delta = deltaClock.restart();

            if(event.type == sf::Event::Closed){
                window.close();
                Game::debug("Window exit called");
            }

            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape){
                window.close();
                Game::debug("Escape key pressed, closing!");
            }

            window.clear(sf::Color(3, 184, 244)); // Sky blue
            update(delta.asSeconds());
            render();

            window.display();

        }
    }
}

void Game::render(){
    // player.render(&window);
    window.draw(sun);
    for(Entity& entity : entities){
        entity.render(&window);
    }
}

void Game::update(float delta){
    // player.update();
    for(Entity& entity : entities){
        entity.update(delta);
    }
}
