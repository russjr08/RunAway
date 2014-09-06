#include "Tile.hpp"
#include "../Game.hpp"

// STATIC
void Tile::loadTileTextures(){
    Game::getInstance()->images.addTexture("dirt", "assets/tiles/dirt.png");
    Game::getInstance()->images.addTexture("grass", "assets/tiles/grass.png");
    Game::getInstance()->images.addTexture("block", "assets/tiles/block.png");

}

Tile::Tile(Tile::TileType type, sf::Vector2i pos){
    _type = type;
    _pos.x = pos.x;
    _pos.y = pos.y;
    _sprite.setPosition(_pos);


    this->initTile();

}

void Tile::initTile() {
    if(_type == Tile::TileType::DIRT){
        _texture = Game::getInstance()->images.getImage("dirt");
    } else if(_type == Tile::TileType::GRASS) {
        _texture = Game::getInstance()->images.getImage("grass");
    }

    if(_type == Tile::TileType::AIR) return;
    _sprite.setTexture(_texture);
}

void Tile::setTileType(Tile::TileType type) {
    _type = type;
    this->initTile();
}

void Tile::update() {
}

void Tile::render(sf::RenderTarget* window) {
    if(_type == Tile::TileType::AIR) return;
    window->draw(_sprite);

}

bool Tile::collideableTile() {
    if(_type != Tile::TileType::AIR) {
        return true;
    }

    return false;
}
