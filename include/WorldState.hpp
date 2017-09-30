#pragma once

#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "SpriteSheet.hpp"
#include "Character.hpp"
#include "Map.hpp"

#include "IGameState.hpp"

class WorldState : public IGameState {

        SDL_Renderer *_renderer;
        std::string _stateName;
        Map *_worldMap;
        SDL_Texture *_texMap;
        SDL_Rect *_pos;
        Character *_player;

        bool _dirKeyDown;

    public:

        WorldState(SDL_Renderer *);
        virtual ~WorldState();

        virtual void InitState();
        virtual void Update();
        virtual void Draw();
        virtual void UnloadState();

        virtual void HandleEvent(SDL_Event);
        virtual void ChangeState();

};