#include "player.hpp"

Player::Player(Rectangle object):
    Sprite(object, ImageIndex::PLAYER)     
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

    object.x += velocity.x * GetFrameTime();
    object.y += velocity.y * GetFrameTime();

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
