#pragma once

#include <SDL2/SDL.h>

class IGameState {

    public:

        virtual ~IGameState() { }

        virtual void InitState() = 0;
        virtual void Update() = 0;
        virtual void Draw() = 0;
        virtual void UnloadState() = 0;

        virtual void HandleEvent(SDL_Event) = 0;
        virtual void ChangeState() = 0;

};