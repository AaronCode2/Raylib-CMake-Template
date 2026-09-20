#pragma once
#include "sprite.hpp"
#include "../utility/utils.hpp"
#include "../utility/textures.hpp"
#include "tile.hpp"
#include <raylib.h>
#include <vector>

class Player : public Sprite {


    public:

        Player(Rectangle object, std::vector<Tile> &tiles);

        void update();

    private:

        void draw();
        void move();
        void handleAnimation();
        void handleFraming();
        void addressInput();
        void handleDirection();

        void applyGravity();
        void updateHitBox();
        
        void collisionX();
        void collisionY();

        Dir direction = Dir::RIGHT;
        PlayerAnimState state = PlayerAnimState::IDLE;

        std::vector<Tile> &tiles;

        Rectangle hitBox;
};