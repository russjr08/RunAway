
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

    _view = sf::View(sf::Vector2f(800 / 2, 600 / 2), sf::Vector2f(800, 600));

    entities.push_back(Player(this, _level));

    window.setFramerateLimit(60);
    window.setView(_view);

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

        window.clear(sf::Color(3, 184, 244)); // Sky blue
        update(delta.asSeconds());
        render();

        window.display();
        fps->update();
    }
}

void Game::render(){
    // Draw Debug Text
    if(Game::DEBUGGING) {
        window.draw(this->getText("RunAway v" + Game::getVersion() + " (Debug/Developer Mode)", 12, sf::Vector2f(this->getViewOffset().x, 0)));
        window.draw(this->getText("FPS: " + std::to_string(fps->getFPS()), 12, sf::Vector2f(this->getViewOffset().x, 12)));
    }

    window.draw(sun);
    _level->render(&window);
    for (Entity& entity : entities){
        entity.render(&window);
    }
}

void Game::update(float delta){
    _level->update(static_cast<sf::Window&>(window));

    for (Entity& entity : entities){
        entity.update(delta);
    }

    // Keep sun constantly on the top-right.
    sun.setPosition(sf::Vector2f((Game::WIDTH - 100) + this->getViewOffset().x, 0));

    window.setView(_view);
}

sf::View& Game::getView() {
    return _view;
}

sf::Vector2f Game::getViewOffset() {
    sf::Vector2f viewCenter = _view.getCenter();
    sf::Vector2f halfExtents = _view.getSize() / 2.0f;
    return viewCenter - halfExtents;

}

sf::Text Game::getText(string msg, unsigned int size, sf::Vector2f pos){
    sf::Text text;
    text.setFont(this->roboto);
    text.setColor(sf::Color::Black);
    text.setString(msg);
    text.setCharacterSize(size);
    text.setPosition(pos);

    return text;

}
