#include "Map.hpp"

Map::Map(std::string mapSpriteName) {
    //this->_yPos = 0;
    //this->_xPos = 0;
    this->_spriteMap.LoadSpriteSheet(mapSpriteName);
}

Map::~Map() {

}

/*void Map::SetCharacterX(int xPos) {
    this->_xPos = xPos;
}

void Map::SetCharacterY(int yPos) {
    this->_yPos = yPos;
}*/

SpriteSheet Map::GetMap() const {
    return (this->_spriteMap);
}

void Map::Unload() {

}