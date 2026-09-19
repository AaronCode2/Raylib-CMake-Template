#include "game.hpp"

Game::Game() {

    SetExitKey(KEY_NULL);
}
 
/*! 
    There maybe be texture that aren't unloaded, if so, report an issue immediately
    on github, as this is a memory leak and only way to fix is to off the computer
    or simply unload it. Don't worry about the __linux__ flag.
!*/

Game::~Game() {

#if !__linux__

#endif
}

void Game::gameLoop() {

    SetTargetFPS(60);

    while(!WindowShouldClose()) {

        BeginDrawing();

            ClearBackground(backgroundColor);
            updateGame();

        EndDrawing();
    }

    CloseWindow();
}

void Game::updateGame() {

    handleFps();

    sprite.update();
}

void Game::handleFps() {

    if(IsKeyPressed(KEY_P)) {
        
        GlobalVar::toggleMaxFPS = !GlobalVar::toggleMaxFPS;

        if(GlobalVar::toggleMaxFPS)
            SetTargetFPS(0);
        else
            SetTargetFPS(60);
    }

    if(!IsWindowFocused() && !GlobalVar::isWindowInactive) {

        SetTargetFPS(30);
        GlobalVar::isWindowInactive = true;

    } else if(IsWindowFocused() && GlobalVar::isWindowInactive) {

        SetTargetFPS(60);
        GlobalVar::isWindowInactive = false;
    }

    DrawFPS(GetScreenHeight() - 40.0f, 40);
}