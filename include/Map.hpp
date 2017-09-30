#pragma once

#include <string>

#include "SpriteSheet.hpp"

#define MAX_HEIGHT_MAP 12
#define MAX_WIDTH_MAP 20

class Map {

        SpriteSheet _spriteMap;

        int _position[12][20];

    public:

        Map(std::string);
        ~Map();

        void SetCharacterX(int);
        void SetCharacterY(int);

        SpriteSheet GetMap() const;

        void Unload();
};