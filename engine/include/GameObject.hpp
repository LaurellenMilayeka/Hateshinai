#pragma once

#include "Engine.hpp"
#include "Core.hpp"
#include "Component.hpp"
#include "Transform.hpp"
#include "Camera.hpp"

namespace Engine {
 
    class GameObject : public Core {

    private:

        std::string _name;
        std::list<Component*> _components;
        std::string _tag;

        int _layer;

        bool _isVisible;
        bool _isTrigger;

        GameObject(std::string, std::string);

    public:

        GameObject();
        ~GameObject();

        void Update();
        void Render();

        static GameObject CreateGameObject(std::string);
        static GameObject CreateGameObject(std::string, std::string);

        std::string GetName() const;
        std::string GetTag() const;
        bool GetIsVisible() const;
        bool GetIsTrigger() const;
        int GetLayer() const;

        void SetName(std::string);
        void SetTag(std::string);
        void SetIsVisible(bool);
        void SetIsTrigger(bool);
        void SetLayer(int);

        template<typename T>
        void AddComponent() {
            static_assert(std::is_base_of<Component, T>::value, "[ERROR] : Constraint violation. Class must inherit from Component.");
            this->_components.insert(this->_components.end(), new T(*this));
        }

        template<typename T>
        T& GetComponent() {
            static_assert(std::is_base_of<Component, T>::value, "[ERROR] : Constraint violation. Class must inherit from Component.");
            std::list<Component*>::iterator itComponents;

            for (itComponents = this->_components.begin(); itComponents != this->_components.end(); itComponents++) {
                if (dynamic_cast<T*>((*itComponents)) != 0) {
                    return (*(dynamic_cast<T*>((*itComponents))));
                }
            }
            std::cout << "[WARNING] : Component \"" << T::GetType() << "\" could not be found on game object \"" << this->_name << "\"." << std::endl;
            return (*(dynamic_cast<T*>(*this->_components.end())));
        }

        template<typename T>
        bool CheckComponent() {
            static_assert(std::is_base_of<Component, T>::value, "[ERROR] : Constraint violation. Class must inherit from Component.");
            std::list<Component*>::iterator itComponents;
            for (itComponents = this->_components.begin(); itComponents != this->_components.end(); itComponents++) {
                if (dynamic_cast<T*>((*itComponents)) != 0) {
                    return (true);
                }
            }
            return (false);        
        }
    };
};