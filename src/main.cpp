/**
 ** Branch development
 ** For the devlopment of your project
 **/

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "SpriteSheet.hpp"
#include "WorldState.hpp"

#ifdef WIN32

int WinMain(int argc, char *argv[]) {
  
#endif

#ifdef LINUX

int main(int argc, char *argv[]) {

#endif
    argc = argc;
    argv = argv;

    unsigned int currentTime = 0;
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Event event;
    bool running = true;

    int flags = IMG_INIT_JPG | IMG_INIT_PNG;
    int result;

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cout << "An error occured while initializing SDL 2" << std::endl << SDL_GetError() << std::endl;
        exit(EXIT_FAILURE);
    }

    if (((result = IMG_Init(flags)) & flags) != flags) {
        std::cout << "An error occured while initializing SDL 2 Image" << std::endl << SDL_GetError() << std::endl;
        exit(EXIT_FAILURE);
    }

    if (SDL_CreateWindowAndRenderer(1280, 720, 0, &window, &renderer) != 0) {
        std::cout << "An error occured while initiliazing window and renderer" << std::endl << SDL_GetError() << std::endl;
        exit(EXIT_FAILURE);
    }

    IGameState *gameState = new WorldState(renderer);
    gameState->InitState();

    while (running) {

        while (SDL_PollEvent(&event)) {
            
            switch (event.type) {
                case SDL_QUIT:
                    running = false;
                    break;
            }

            gameState->HandleEvent(event);            
        }

        gameState->Update();
        gameState->Draw();

        while (SDL_GetTicks() < currentTime + 17);
        currentTime = SDL_GetTicks();

    }

    gameState->UnloadState();

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();

    return (0);
}
