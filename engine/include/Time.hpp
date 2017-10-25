#pragma once

#include "Engine.hpp"

namespace Engine {

    class Time {

    private:
        
        static int _lastTime;

    public:

        static int GetTime();
        static double GetLastFrameTime();

    };
};