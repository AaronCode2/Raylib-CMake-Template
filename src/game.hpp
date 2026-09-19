#pragma once
#include <iostream>
#include <raylib.h>
#include "utility/global_vars.hpp"
#include "entity_classes/sprite.hpp"
#include "utility/textures.hpp"

class Game {

    public:

        Game();
        ~Game();

        void run() { gameLoop(); };

    private:

        Color backgroundColor = {100, 100, 100, 155};

        Sprite sprite = Sprite({100, 100, 100, 100}, {1, 1}, ImageIndex::PLAYER);

        void gameLoop();
        void updateGame();
        void handleFps();
};