#include "world.hpp"

World::World() {

}

void World::updateTiles(const Vector2 playerVelocity, const ShouldCameraMove cameraMovement) {

    if(cameraMovement.moveX) {

        for(Tile &tile : tiles) {

            tile.move({roundf(-playerVelocity.x), 0});
        }
    }

    if(cameraMovement.moveY) {

        for(Tile &tile : tiles) {

            tile.move({0, roundf(-playerVelocity.y)});
        }
    }

    for(Tile &tile : tiles) {

        tile.update();
    }    
}

void World::update(const Vector2 playerVelocity, const ShouldCameraMove cameraMovement) {

    updateTiles(playerVelocity, cameraMovement);

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
