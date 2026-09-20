#include "world.hpp"

World::World() {

    tiles.push_back(Tile({100, 100}, TileType::WALL));
}

void World::update() {

    for(Tile &tile : tiles) {

        tile.update();
    }

#if DEBUG_ENABLED

    dev_tilePlacer();

#endif
}

void World::dev_tilePlacer() {

    // stuff
}
