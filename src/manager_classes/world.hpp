#pragma once
#include <raylib.h>
#include <vector>
#include "../entity_classes/tile.hpp"

class World {

    public:

        World();

        void update();

    private:

        void dev_tilePlacer();

        std::vector<Tile> tiles;

        Vector2 worldPos = {0, 0};
};