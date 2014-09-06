#include "Level.hpp"

Level::Level(std::string levelFile) {
    // TODO: Replace this with actual level loading / parsing

    // Add air tiles

    for(int y = 0; y < 18 * 32; y += 32) {
        for(int x = 0; x < 25 * 32; x += 32) {
            _tiles.push_back(new Tile(Tile::TileType::AIR, sf::Vector2i(x, y)));
        }
    }

    // Add intial background stuffs
    for(int i = 0; i < 25 * 32; i += 32) {
        _tiles.push_back(new Tile(Tile::TileType::DIRT, sf::Vector2i(i, Game::HEIGHT - 32)));
        _tiles.push_back(new Tile(Tile::TileType::GRASS, sf::Vector2i(i, Game::HEIGHT - 64)));
    }
}

Tile* Level::getTile(sf::Vector2i pos) {
    int x = pos.x;
    int y = pos.y;

    for(auto tile : _tiles) {
        if((tile->getPos().x <= x && tile->getPos().x + Tile::TILE_SIZE >= x
            && tile->getPos().y <= y && tile->getPos().y + Tile::TILE_SIZE >= y)) {
            return tile;
        }
    }
    return new Tile(Tile::TileType::AIR, pos);
}

void Level::render(sf::RenderTarget* window) {

    for(auto tile : _tiles) {
        tile->render(window);
    }

}

void Level::update(sf::Window& window) {

    for(auto tile : _tiles) {
        tile->update();
    }

    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        int x = (sf::Mouse::getPosition(window).x + Game::getInstance()->getViewOffset().x) + 1; // (The + 1 fixes some mouse oddities!)
        int y = sf::Mouse::getPosition(window).y;

        this->getTile(sf::Vector2i(x, y))->setTileType(Tile::TileType::DIRT);
    }

}

// TODO: Patch this up. It's faulty!
bool Level::colliding(sf::FloatRect boundingBox, sf::Vector2i pos) {
    // Game::debug(std::to_string(getTile(sf::Vector2i(pos.x, pos.y))->getTileType()));
    return boundingBox.intersects(getTile(sf::Vector2i(pos.x, pos.y))->getBoundingBox());
}
