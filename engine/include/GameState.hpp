#pragma once

#include "Engine.hpp"
#include "GameObject.hpp"

namespace Engine {
    
    class GameState : public Core {
        private:

            std::list<GameObject> _objects;
            
        public:

            void AddGameObject(GameObject const&);
            
            std::list<GameObject> const& GetObjects() const;
            GameObject const& GetObjectByName(std::string const&) const;
            std::list<GameObject> GetObjectsByTag(std::string const&) const;
            
        public:

            GameState();
            virtual ~GameState();

            virtual void Start();
            virtual void Update();
            virtual void Render();
            virtual void End();
    };
};