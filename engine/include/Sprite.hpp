#pragma once

#include "Engine.hpp"
#include "Component.hpp"
#include "Vector2.hpp"
#include "Texture.hpp"
#include "CharacterController.hpp"
#include "CharacterAnimator.hpp"
#include "GameObject.hpp"
#include "Transform.hpp"

namespace Engine {

    class Sprite : public Component {

    private:
    
        Vector2 _relativePosition;

    public:
        Texture _spriteTex;
        
        Sprite() { }
        Sprite(GameObject&);
        ~Sprite();

        static std::string const GetType();

        virtual void Update();
        virtual void Render();

        void SetTexture(std::string const&);
        void SetTexture(Texture const&);

    };
};