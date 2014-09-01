#include "Tile.hpp"
#include "../Game.hpp"

// STATIC
void Tile::loadTileTextures(){
    Game::getInstance()->images.addTexture("dirt", "assets/tiles/dirt.png");
    Game::getInstance()->images.addTexture("grass", "assets/tiles/grass.png");
    Game::getInstance()->images.addTexture("block", "assets/tiles/block.png");

}

Tile::Tile(Tile::TileType type, sf::Vector2f pos){
    _type = type;
    _pos = pos;

    if(_type == Tile::TileType::DIRT){
        _texture = Game::getInstance()->images.getImage("dirt");
    } else if(_type == Tile::TileType::GRASS) {
        _texture = Game::getInstance()->images.getImage("grass");
    }

    _sprite.setTexture(_texture);
}

void Tile::update() {
    _sprite.setPosition(_pos);
}

void Tile::render(sf::RenderTarget* window) {
    window->draw(_sprite);

}
