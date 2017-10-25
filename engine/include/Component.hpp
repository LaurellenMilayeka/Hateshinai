#pragma once

#include <string>

namespace Engine {

    class GameObject;

    class Component {

    protected:

        GameObject *_source;

        Component() { }
        Component(GameObject& source);

        static std::string GetType() { return ("Component"); }

    public:
        
        virtual ~Component() { }

        GameObject& GetGameObject() const;
        
        virtual void Update() { }
        virtual void Render() { }

    };
};