#pragma once

#include "Engine.hpp"
#include "Component.hpp"
#include "Vector2.hpp"
#include "GameObject.hpp"
#include "Transform.hpp"
#include "Input.hpp"

namespace Engine {

    typedef enum DIRECTIONS {
        DOWN,
        UP,
        LEFT,
        RIGHT
    } DIRECTION;

    class CharacterController : public Component {

        private:
    
            bool _isMoving;
            DIRECTION _actualDirection;
            Vector2 _lastPosition;
            int _speed;

            void MoveCharacter();

        public:

            CharacterController(GameObject&);
            ~CharacterController();

            static std::string const GetType();

            bool GetIsMoving() const;
            DIRECTION GetDirection() const;

            void SetSpeed(int);
            
            void Update();

    };
};