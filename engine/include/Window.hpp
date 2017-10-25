#pragma once

#include "Engine.hpp"

namespace Engine {

    class Window {

    private:

        std::string _windowName;

        size_t _windowHeight, _windowWidth;

        bool _isCurrentContext;

        static GLFWwindow *_window;

    public:

        Window();

        void CreateWindow(std::string const&, size_t, size_t, bool = true);

        std::string GetWindowName();
        size_t GetWindowHeight();
        size_t GetWindowWidth();

        void SetActiveContext();
        bool Quit();

        static GLFWwindow* GetWindow();

        void RefreshDisplay();

        void SetTitle(std::string newWindowName);

    };
};