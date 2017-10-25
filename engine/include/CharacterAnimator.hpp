#pragma once

#include "Engine.hpp"
#include "Component.hpp"
#include "GameObject.hpp"
#include "Time.hpp"

namespace Engine {

    typedef enum ANIMATIONS {
        WALK_DOWN = 3,
        WALK_LEFT = 2,
        WALK_RIGHT = 1,
        WALK_UP = 0,
    } ANIMATION;

    class CharacterAnimator : public Component {

        private:

            int _frame;

            int _animationSpeed;
    
            int _frameWidth;
            int _frameHeight;
            int _nbFrames;

            int _lastTime;

            bool _animPlaying;
            bool _animPaused;

            ANIMATION _actualAnim;

        public:

            CharacterAnimator(GameObject&);
            ~CharacterAnimator();

            static std::string const GetType();   
            
            virtual void Update();

            int GetFrameWidth() const;
            int GetFrameHeight() const;
            int GetNbFrames() const;
            ANIMATION GetAnimation() const;
            int GetFrame() const;

            void SetFrameWidth(int);
            void SetFrameHeight(int);
            void SetNbFrames(int);
            void SetAnimation(ANIMATION);
            void SetAnimationSpeed(int);

            void PlayAnimation();
            void PauseAnimation();
            void StopAnimation();

    };
};