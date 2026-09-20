#pragma once
#include <raylib.h>
#include <iostream>
#include <fstream>

#define print(x) std::cout << x << '\n'
#define EMPTY_RECT (Rectangle) {0, 0, 0, 0}
#define WH_EMPTY_RECT (Rectangle) {0, 0, TILE_SIZE, TILE_SIZE}

#define SAVY_YELLOW (Color) {255, 209, 157, 255}
#define MOUSE_BROWN (Color) {163, 90, 66, 255}
#define SAVY_BROWN (Color) {215, 147, 106, 255}
#define DARK_BROWN (Color) {181, 108, 78, 255}

#define FONT_SIZE 30
#define FONT_SPACING 1
#define SLOT_SIZE 120

#define STACK_SIZE 255

struct Input {

    bool goingLeft;
    bool goingRight;
    bool isJumping;
};

Input getInput();

enum class FPS_TYPE {

   THIRTY_FPS = 0, // Can't write nums in enum!
   SIXTY_FPS,
   HUNDRED_AND_TWENTY_FPS,
   MAXFPS
};

enum class Dir {

    LEFT = 0,
    RIGHT
};

enum class PlayerAnimState {

    IDLE = 0,
    WALK
};

namespace Utils {

    extern float deltaTimeIt;
    extern Color const testColor;
    Rectangle getScreenRect(); 

    std::string formatZeros(int num, int width);
    extern int fontSize;

    bool isSameXY(const Rectangle aObject, const Rectangle bObject);
    bool isSameXY(const Vector2 aObject, const Vector2 bObject);
    bool isSameXY(const Vector2 aObject, const Vector2 bObject, const Vector2 bObject2);
    
    void collisionActionX(Rectangle &aObject, const Rectangle ahitBox, const Rectangle bHitBox, Vector2 &aVelocity, bool resetVelocity = true);
    void collisionActionY(Rectangle &aObject, const Rectangle ahitBox, const Rectangle bHitBox, Vector2 &aVelocity, bool resetVelocity = true);

    void exitApp(const std::string errorInfo);

    extern Font font;

#if DEBUG_ENABLED

    extern float xdebugingvalue;
    extern float ydebugingvalue;

    void TheDebugFunc();
#endif
} 


namespace Mouse {

    bool isHovering(const Rectangle object);
    bool isClickedL(const Rectangle object);
    bool isClickedR(const Rectangle object);

    bool isClickedOnceR(const Rectangle object);
    bool isClickedOnceL(const Rectangle object);
}

// constants

#define MAX_AMOUNT_OF_IMAGES 2

#define IMAGE_PLAYER_PATH "../assets/player/player.png"
#define IMAGE_PLAYER_MAX_FRAMES (Vector2) {8, 2}

#define IMAGE_TILE_PATH "NULL"
#define IMAGE_TILE_MAX_FRAMES (Vector2) {1, 1}

#define PLAYER_IDLE_FRAME_DURATION 0.1f
#define PLAYER_IDLE_MAX_FRAMES 5

#define PLAYER_WALK_FRAME_DURATION 0.09f
#define PLAYER_WALK_MAX_FRAMES 8

#define PLAYER_SPEED 20000
#define GRAVITY 2000