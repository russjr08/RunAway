#pragma once

#include <SFML/Graphics.hpp>

class Tile {

public:
    enum TileType {
        DIRT = 1,
        GRASS
    };

    Tile(Tile::TileType, sf::Vector2f);

    static void loadTileTextures();

    void render(sf::RenderTarget*);
    void update();

private:
    TileType _type;

    sf::Sprite _sprite;
    sf::Texture _texture;

    sf::Vector2f _pos;

};
