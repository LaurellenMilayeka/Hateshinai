#pragma once

#include <iostream>

#include <SDL2/SDL.h>

class Animation {

#define DEFAULT_ANIMATION_SPEED 164

        int _frame;
        int _speed;
        unsigned int _currentTime;
        unsigned int _lastTime;

    public:

        typedef enum ANIMATIONS {
            WALK_DOWN = 0,
            WALK_LEFT = 1,
            WALK_RIGHT = 2,
            WALK_UP = 3,
            IDLE
        } ANIMATION;

        typedef enum ANIMATION_STATES {
            PLAYING,
            PAUSED,
            STOPPED
        } ANIMATION_STATE;

        Animation();
        ~Animation();

        void SetAnimation(ANIMATION);
        ANIMATION GetAnimation() const;

        void PlayAnimation();
        void PauseAnimation();
        void ResumeAnimation();
        void StopAnimation();

        void Step();

        int GetAnimationFrame() const;
        int GetAnimationSpeed() const;
        ANIMATION_STATE GetAnimationState() const;

        void SetAnimationSpeed(int);
        void SetAnimationFrame(int);
        void SetAnimationState(ANIMATION_STATE);

    private:
        
        ANIMATION_STATE _state;
        ANIMATION _actualAnimation;
};