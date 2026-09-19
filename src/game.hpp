#pragma once
#include <iostream>
#include <raylib.h>
#include "utility/global_vars.hpp"

class Game {

    public:

        Game();
        ~Game();

        void run() { gameLoop(); };

    private:

        Color backgroundColor = {130, 235, 207, 255};

        void gameLoop();
        void updateGame();
        void handleFps();
};