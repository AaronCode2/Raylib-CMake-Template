#include "player.hpp"

Player::Player(Rectangle object, std::vector<Tile> &tiles):
    Sprite(object, ImageIndex::PLAYER), tiles(tiles)     
{

    object.width = srcRect.width;
    object.height = srcRect.height;
}

void Player::update() {

    addressInput();
    move();

    draw();
}

void Player::draw() {

    applyGravity();
    handleAnimation();

    DrawTextureRec(
        Textures::texture[ImageIndex::PLAYER].texture,
        srcRect, 
        {object.x, object.y},
        WHITE
    );

}

void Player::move() {

    updateCamera();

    object.x += velocity.x;
    collisionX();
    moveCameraX();

    object.y += velocity.y;
    collisionY();
    moveCameraY();
}

void Player::handleAnimation() {

    // My python is against me

    if(velocity.x == 0) {

        if(state != PlayerAnimState::IDLE) {

            state = PlayerAnimState::IDLE;
            currentFrame = 0;
            srcRect.y = 0;
        }
        
        handleDirection();
        animate(PLAYER_IDLE_MAX_FRAMES, PLAYER_IDLE_FRAME_DURATION);
        handleFraming();
    } else {        

        if(state != PlayerAnimState::WALK) {

            state = PlayerAnimState::WALK;
            currentFrame = 0;
            srcRect.y = srcRect.height;
        }

        handleDirection();
        handleFraming();
        animate(PLAYER_WALK_MAX_FRAMES, PLAYER_WALK_FRAME_DURATION);
    }
}

void Player::handleFraming() {

    if(direction == Dir::RIGHT)
        srcRect.x = srcRect.width * currentFrame;
    else
        srcRect.x = srcRect.width * (IMAGE_PLAYER_MAX_FRAMES.x - currentFrame);
}

void Player::addressInput() {

    velocity.x = 0;

    if(getInput().goingLeft)
        velocity.x = -PLAYER_SPEED * GetFrameTime();
    if(getInput().goingRight)
        velocity.x = PLAYER_SPEED * GetFrameTime();

    if(getInput().isJumping)
        velocity.y = PLAYER_JUMP_SPEED * GetFrameTime();
}

void Player::handleDirection() {

    if(velocity.x < 0 && direction == Dir::RIGHT) {

        direction = Dir::LEFT;
        srcRect.width = -srcRect.width;
    } else if(velocity.x > 0 && direction == Dir::LEFT) {

        direction = Dir::RIGHT;
        srcRect.width = abs(srcRect.width);
    }
}

void Player::applyGravity() {

    if(object.y + object.height <= GetScreenHeight() - 100)
        velocity.y += GRAVITY * GetFrameTime();
    else
        velocity.y = 0;
}

void Player::updateHitBox() {

    hitBox = {

        object.x + PLAYER_HITBOX_ADJ.x,
        object.y + PLAYER_HITBOX_ADJ.y,
        object.width + PLAYER_HITBOX_ADJ.width,
        object.height + PLAYER_HITBOX_ADJ.height,   
    };

    Utils::debugRect(hitBox);
}

void Player::collisionX() {

    updateHitBox();

    for(auto &tile : tiles) {

        if(CheckCollisionRecs(hitBox, tile.getHitBox())) {
            
            if(velocity.x > 0) {
                
                const float offset = hitBox.x - object.x + hitBox.width;
                
                object.x = tile.getHitBox().x - offset - COL_ADJUST;
            }
            
            if(velocity.x < 0) {
                
                const float offset = hitBox.x - object.x;
                
                object.x = tile.getHitBox().x + tile.getHitBox().width - offset + COL_ADJUST;
            }

            velocity.x = 0;
        }
    }
}

void Player::collisionY() {

    updateHitBox();

    for(auto &tile : tiles) {

        if(CheckCollisionRecs(hitBox, tile.getHitBox())) {

            if(velocity.y > 0) {
                
                velocity.y = 0;
                
                const float offset = hitBox.y - object.y + hitBox.height;
                
                object.y = tile.getHitBox().y - offset - COL_ADJUST;
            }

            if(velocity.y < 0) {

                velocity.y = 0;

                const float offset = hitBox.y - object.y;

                object.y = tile.getHitBox().y + tile.getHitBox().height - offset + COL_ADJUST;
            }
        }
    }
}

void Player::moveCameraX() {

    if((hitBox.x <= cameraBox.x || hitBox.x + hitBox.width >= cameraBox.x + cameraBox.width) && velocity.x != 0) {

        object.x -= velocity.x;
        shouldCameraMove.moveX = true;
    }
}

void Player::moveCameraY() {

    if((hitBox.y <= cameraBox.y || hitBox.y + hitBox.height >= cameraBox.y + cameraBox.height) && velocity.y != 0) {

        object.y -= velocity.y;
        shouldCameraMove.moveY = true;
    }
}

void Player::updateCamera() {

    shouldCameraMove = {false, false};

    cameraBox = {

        CAMERA_BOX_ADJ.x,
        CAMERA_BOX_ADJ.y,
        GetScreenWidth() - CAMERA_BOX_ADJ.width,
        GetScreenHeight() - CAMERA_BOX_ADJ.height,
    };

    Utils::debugRect(cameraBox);
}