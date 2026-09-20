#include "world.hpp"

World::World() {

}

void World::update() {

    for(Tile &tile : tiles) {

        tile.update();
    }

#if DEBUG_ENABLED

    if(IsKeyPressed(KEY_T))
        enableTilePlacer = !enableTilePlacer;

    if(enableTilePlacer)
        dev_tilePlacer();

#endif
}

std::vector<Tile> &World::giveTiles() {

    return tiles;
}

void World::dev_tilePlacer() {

    if(GetMouseDelta().x != 0 || GetMouseDelta().y != 0) {

        for(float x = 0; x < tileSize.x * 200; x += tileSize.x) {
            for(float y = 0; y < tileSize.y * 200; y += tileSize.y) {

                if(CheckCollisionPointRec(GetMousePosition(), {x, y, tileSize.x, tileSize.y})) {
                    tilePlacerRect = {x, y, tileSize.x, tileSize.y};
                    break;
                }
            }
        }
    }

    if(IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {

        for(auto &tile : tiles) {

            if(CheckCollisionPointRec(GetMousePosition(), tile.getObject()))
                return;
        }

        tiles.push_back(Tile({tilePlacerRect.x, tilePlacerRect.y}, pickedTile));
    } else if(IsMouseButtonDown(MOUSE_BUTTON_RIGHT)) {

        for(auto it = tiles.begin(); it < tiles.end(); it++) {

            if(CheckCollisionPointRec(GetMousePosition(), it->getObject())) {
                it = tiles.erase(it);
                return;
            }
        }
    }

    Utils::debugRect(tilePlacerRect);
}
