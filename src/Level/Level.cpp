#include "Level.hpp"

Level::Level(std::string levelFile) {
    // TODO: Replace this with actual level loading / parsing
    for(int i = 0; i < 25 * 32; i++) {
        _tiles.push_back(new Tile(Tile::TileType::DIRT, sf::Vector2f(i, Game::HEIGHT - 32)));
        _tiles.push_back(new Tile(Tile::TileType::GRASS, sf::Vector2f(i, Game::HEIGHT - 64)));
    }
}

void Level::render(sf::RenderTarget* window) {

    for(auto tile : _tiles) {
        tile->render(window);
    }

}

void Level::update() {

    for(auto tile : _tiles) {
        tile->update();
    }

}
