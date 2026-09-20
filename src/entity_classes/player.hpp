#pragma once
#include "sprite.hpp"
#include "../utility/utils.hpp"
#include "../utility/textures.hpp"
#include <raylib.h>

class Player : public Sprite {


    public:

        Player(Rectangle object);

        void update();

    private:

        void draw();
        void move();
        void handleAnimation();
        void handleFraming();
        void addressInput();
        void handleDirection();

        void applyGravity();

        Dir direction = Dir::RIGHT;
        PlayerAnimState state = PlayerAnimState::IDLE;

        Rectangle hitBox;
};