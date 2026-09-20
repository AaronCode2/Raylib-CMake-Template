#pragma once
#include <iostream>
#include <raylib.h>
#include "utility/global_vars.hpp"
#include "entity_classes/sprite.hpp"
#include "entity_classes/player.hpp"
#include "utility/textures.hpp"
#include "manager_classes/world.hpp"

class Game {

    public:

        Game();
        ~Game();

        void run() { gameLoop(); };

    private:

        Color backgroundColor = {100, 100, 100, 155};

        Player player = Player({100, 100, 100, 100});
        World world = World();

        void gameLoop();
        void updateGame();
        void handleFps();
};