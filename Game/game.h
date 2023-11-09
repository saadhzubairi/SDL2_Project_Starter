#ifndef BOXIDOXI_GAME_H
#define BOXIDOXI_GAME_H

#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"
#include "SDL_image.h"

class game {
public:
    game();
    ~game();

    void init(const char *title, int x, int y, int width, int height, bool fullscreen);
    void handleEvents();
    void update();
    void render();
    void clean();
    [[nodiscard]] bool running() const { return isRunning; };
    static SDL_Event event;
    static SDL_Renderer *renderer;

private:
    bool isRunning{};
    SDL_Window *window{};
};

#endif //BOXIDOXI_GAME_H
