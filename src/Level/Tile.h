#ifndef TILE_H
#define TILE_H


class Tile {

public:
    enum TileType {
        DIRT = 1,
        GRASS
    };

    static void loadTileTextures();

private:
    TileType type;

};

#endif TILE_H
