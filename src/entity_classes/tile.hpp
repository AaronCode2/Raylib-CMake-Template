#pragma once
#include <raylib.h>
#include "sprite.hpp"
#include "../utility/textures.hpp"
#include "../utility/utils.hpp"

class Tile : public Sprite {

    public:

        Tile(Vector2 position, TileType type);

        void update();

        Rectangle getHitBox() const { return hitBox; };

    private:

        void draw();
        void updateHitBox();

        TileType type;
        Rectangle hitBox;
};