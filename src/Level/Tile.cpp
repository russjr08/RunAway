#include "Tile.hpp"
#include "../Game.hpp"

void Tile::loadTileTextures(){
    Game::getInstance()->images.addTexture("dirt", "assets/tiles/dirt.png");
    Game::getInstance()->images.addTexture("grass", "assets/tiles/grass.png");
    Game::getInstance()->images.addTexture("block", "assets/tiles/block.png");

}
