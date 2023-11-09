#include "game.h"
#include <iostream>

game::game() = default;
game::~game() = default;
SDL_Renderer *game::renderer = nullptr;

SDL_Event game::event;

void game::init(const char *title, int x, int y, int w, int h, bool fullscreen) {
    int flags = 0;
    if (fullscreen) {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        std::cout << "[+] SDL initialized!" << std::endl;
        window = SDL_CreateWindow(title, x, y, w, h, flags);
        if (window) {
            std::cout << "[+] Window created!" << std::endl;
        }
        game::renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        if (game::renderer) {
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            std::cout << "[+] Renderer Created!" << std::endl;
        }

        if (TTF_Init() == -1) {
        } else {
            std::cout << "[+] SDL_ttf Initialized!" << std::endl;
        }
        isRunning = true;

        if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
            printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
        else printf("[+] SDL_Mixer Initialized\n");

    } else { isRunning = false; }

}

void game::handleEvents() {

    SDL_PollEvent(&event);
    switch (event.type) {
        case SDL_QUIT:
            isRunning = false;
            break;
        default:
            break;
    }
}

void game::update() {

}

void game::render() {
    SDL_RenderClear(game::renderer);
    SDL_RenderPresent(game::renderer);
}

void game::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(game::renderer);
    SDL_Quit();
    std::cout << "[+] game Cleaned!" << std::endl;
}
