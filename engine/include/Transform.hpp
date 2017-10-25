#pragma once

#include "Engine.hpp"
#include "Component.hpp"
#include "Transform.hpp"
#include "Vector2.hpp"

namespace Engine {

    class Transform : public Component {

    private:

        Vector2 _position;
        Vector2 _scale;

        Vector2 _destination;
        
    public:

        Transform() { }
        Transform(GameObject&);
        ~Transform();

        static std::string const GetType();

        Vector2 const& GetPosition() const;
        Vector2 const& GetScale() const;

        void SetPosition(Vector2 const&);
        void SetPosition(double, double);

        void Translate(Vector2 const&);
        void MoveTowards(Vector2 const&);

        void SetScale(Vector2 const&);

        virtual void Update();
        virtual void Render();
    };
};