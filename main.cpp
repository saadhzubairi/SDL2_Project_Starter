#include <iostream>
#include "Game/game.h"


game *Game = nullptr;

int main( int argc, char* args[] )
{
    Game = new game();

    const int FPS = 60;
    const int frameDelay = 1000 / FPS;

    Uint32 frameStart;
    int frameTime;

    Game->init("Game Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, false);

    bool check_end = false;

    while (Game->running()) {


        frameStart = SDL_GetTicks();
        Game->handleEvents();
        Game->update();
        Game->render();

        frameTime = SDL_GetTicks() - frameStart;

        if (frameDelay > frameTime) {
            SDL_Delay(frameDelay - frameTime);
        }
    }

    Game->clean();

    return 0;
}
