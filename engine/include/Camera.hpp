#pragma once

#include "Engine.hpp"

namespace Engine {

    class Camera : public Component {

        private:

            float _posX, _posY, _posZ;
            float _centerX, _centerY, _centerZ;
            float _upX, _upY, _upZ;

        public:
    
            Camera(float, float, float);
            Camera(float, float, float, float, float, float);
            Camera(float, float, float, float, float, float, float, float, float);

    };
};