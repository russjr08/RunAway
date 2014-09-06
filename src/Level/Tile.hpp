#pragma once

#include <SFML/Graphics.hpp>

class Tile {

public:
    enum TileType {
        AIR = 0,
        DIRT = 1,
        GRASS
    };

    Tile(Tile::TileType, sf::Vector2i);

    static void loadTileTextures();

    static const int TILE_SIZE = 32;

    void render(sf::RenderTarget*);
    void update();

    void setTileType(Tile::TileType);

    bool collideableTile();
    inline Tile::TileType getTileType() { return _type; }


    inline sf::Vector2f getPos() { return _pos; }

private:
    TileType _type;

    sf::Sprite _sprite;
    sf::Texture _texture;

    sf::Vector2f _pos;

    void initTile();

};
