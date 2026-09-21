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

        Vector2 getVelocity() const { return velocity; };
        ShouldCameraMove getCameraMoved() const { return shouldCameraMove; };

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

        void moveCameraX();
        void moveCameraY();
        void updateCamera();

        Dir direction = Dir::RIGHT;
        PlayerAnimState state = PlayerAnimState::IDLE;
        ShouldCameraMove shouldCameraMove;

        std::vector<Tile> &tiles;

        Rectangle cameraBox;
        Rectangle hitBox;
};