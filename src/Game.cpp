
#include <SFML/Graphics.hpp>

#include <map>

#include "Game.hpp"
#include "Entity/Player.hpp"
#include "Level/Tile.hpp"
#include "FPS.hpp"

sf::RenderWindow window(sf::VideoMode(Game::WIDTH, Game::HEIGHT), "RunAway!");

sf::Clock deltaClock;

sf::CircleShape sun(50);

std::vector<Entity> entities;

Game* Game::instance;

FPS* fps;


int main(){

    Game game;
    game.open();

    return 0;

}

void Game::open(){

    instance = this;
    fps = new FPS();

    Tile::loadTileTextures();

    _level = new Level("assets/level/lvl1.tmx");

    entities.push_back(Player(this, _level));

    window.setFramerateLimit(60);

    sun.setFillColor(sf::Color::Yellow);
    sun.setPosition(sf::Vector2f(Game::WIDTH - 100, 0));

    if (!this->roboto.loadFromFile("assets/fonts/roboto.ttf")){
        Game::error("Failed to load main game font!");
    }


    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){

            if(event.type == sf::Event::Closed){
                window.close();
                Game::debug("Window exit called");
            }

            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape){
                window.close();
                Game::debug("Escape key pressed, closing!");
            }


        }

        sf::Time delta = deltaClock.restart();
        Game::debug(std::to_string(fps->getFPS()));
        
        window.clear(sf::Color(3, 184, 244)); // Sky blue
        update(delta.asSeconds());
        render();

        window.display();
        fps->update();
    }
}

void Game::render(){
    // player.render(&window);
    window.draw(sun);
    _level->render(&window);
    for (Entity& entity : entities){
        entity.render(&window);
    }
}

void Game::update(float delta){
    // player.update();
    _level->update();
    for (Entity& entity : entities){
        entity.update(delta);
    }
}


sf::Text Game::getText(string msg, unsigned int size){
    sf::Text text;
    text.setFont(this->roboto);
    text.setString(msg);
    text.setCharacterSize(size);

    return text;

}
