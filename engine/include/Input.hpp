#pragma once

#include "Engine.hpp"
#include "Key.hpp"
#include "Window.hpp"

namespace Engine {

    class Input {

    private:

        static Key _lastFrameKey;

    public:

        static bool GetKey(Key);
        static bool GetKeyDown(Key);
        static Key GetLastKeyState();

        static void Update();
    };
};