#include "GameState.hpp"

using namespace Engine;

GameState::GameState() {

}

GameState::~GameState() {

}

void GameState::AddGameObject(GameObject const& toAdd) {
    this->_objects.insert(this->_objects.end(), toAdd);
}

std::list<GameObject> const& GameState::GetObjects() const {
    return (this->_objects);
}

GameObject const& GameState::GetObjectByName(std::string const& toSearch) const {
    std::list<GameObject>::const_iterator itObjects;

    for (itObjects = this->_objects.begin(); itObjects != this->_objects.end(); itObjects++) {
        if ((*itObjects).GetName().compare(toSearch)) {
            return ((*itObjects));
        }
    }
    std::cerr << "[WARNING] : Couldn't find game object with name : " << toSearch << std::endl;
}

std::list<GameObject> GameState::GetObjectsByTag(std::string const& toSearch) const {
    std::list<GameObject>::const_iterator itObjects;
    std::list<GameObject> toReturn;

    for (itObjects = this->_objects.begin(); itObjects != this->_objects.end(); itObjects++) {
        if ((*itObjects).GetTag().compare(toSearch)) {
            toReturn.insert(toReturn.end(), (*itObjects));
        }
    }
    return (toReturn);
}

void GameState::Start() {

}

void GameState::Update() {
    std::list<GameObject>::iterator itObjects;

    for (itObjects = this->_objects.begin(); itObjects != this->_objects.end(); itObjects++) {
        (*itObjects).Update();
    }
}

void GameState::Render() {
    std::list<GameObject>::iterator itObjects;

    for (itObjects = this->_objects.begin(); itObjects != this->_objects.end(); itObjects++) {
        (*itObjects).Render();
    }
}

void GameState::End() {
    
}