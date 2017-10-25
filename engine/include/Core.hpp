#pragma once

#include "Engine.hpp"
#include "Window.hpp"
#include "Input.hpp"

namespace Engine {

    class GameState;

    class Core {

        private:

            Window _window;
            std::stack<GameState*> _states;

        public:

            void AddGameState(GameState*);

            std::stack<GameState*> const& GetStates() const;
            Window const& GetWindow() const;

        public:

            Core();
            ~Core();

            void Init();
            void Run();
            virtual void Start();
            virtual void Update();
            void Render();

            bool IsRunning();
    
    };
};