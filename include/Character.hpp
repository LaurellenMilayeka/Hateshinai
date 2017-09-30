#pragma once

#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Entity.hpp"
#include "Animation.hpp"
#include "SpriteSheet.hpp"

#define WIDTH_MAP_CASE 64
#define HEIGHT_MAP_CASE 60

class Character : public Entity {

        int _strength;
        int _power;
        int _wisdom;
        int _agility;
        int _vitality;
        int _speed;
        int _constitution;
        int _spirit;

        int _cp;

        SDL_Texture *_characterSprite;

        SpriteSheet _characterSpriteSheet;
        Animation *_characterAnimation;

        int _mapPositionX;
        int _mapPositionY;

        double _pixPositionX;
        double _pixPositionY;

    public:

        typedef enum STATES {
            MOVING = 0x01,
            IDLE = 0x10
        } STATE;

        typedef enum DIRECTIONS {
            UP,
            DOWN,
            LEFT,
            RIGHT
        } DIRECTION;

        Character(std::string, std::string, SDL_Renderer*);
        ~Character();

        int GetStrength() const;
        int GetPower() const;
        int GetWisdom() const;
        int GetAgility() const;
        int GetVitality() const;
        int GetSpeed() const;
        int GetConstitution() const;
        int GetSpirit() const;
        int GetMapPositionX() const;
        int GetMapPositionY() const;

        void SetStrength(int);
        void SetPower(int);
        void SetWisdom(int);
        void SetAgility(int);
        void SetVitality(int);
        void SetSpeed(int);
        void SetConstitution(int);
        void SetSpirit(int);
        void SetMapPositionX(int);
        void SetMapPositionY(int);

        int GetCompetencePoint() const;
        void SetCompetencePoint(int);

        STATE GetState() const;
        void SetState(STATE);

        DIRECTION GetDirection() const;
        void SetDirection(DIRECTION);

        double GetPixPositionX();
        double GetPixPositionY();

        void SetPixPositionX(double);
        void SetPixPositionY(double);

        SDL_Texture *GetCharacterSprite() const;

        void LoadAnimation();
        void PlayAnimation();
        void PauseAnimation();
        void StopAnimation();

        Animation::ANIMATION_STATE GetAnimationState() const;

        void SetAnimation(Animation::ANIMATION);

        void StepAnimation();

        void SetAnimationSpeed();
        void ResetAnimationSpeed();

        SDL_Rect *GetActualFramePosition();

    private:

        DIRECTION _characterDirection;
        STATE _characterState;

};