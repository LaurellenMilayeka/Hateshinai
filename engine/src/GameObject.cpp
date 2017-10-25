#include "GameObject.hpp"

using namespace Engine;

GameObject::GameObject(std::string name, std::string tag) {
    this->_name = name;
    this->_tag = tag;
    this->_layer = 1;
    this->_isVisible = true;
    this->AddComponent<Transform>();
}

GameObject::~GameObject() {

}

void GameObject::Update() {
    std::list<Component*>::iterator itComponents;

    for (itComponents = this->_components.begin(); itComponents != this->_components.end(); itComponents++) {
        (*itComponents)->Update();
    }
}

void GameObject::Render() {
    std::list<Component*>::iterator itComponents;

    for (itComponents = this->_components.begin(); itComponents != this->_components.end(); itComponents++) {
        (*itComponents)->Render();
    }
}

GameObject GameObject::CreateGameObject(std::string name) {
    GameObject newGameObject(name, "Default");
    return (newGameObject);
}

GameObject GameObject::CreateGameObject(std::string name, std::string tag) {
    GameObject newGameObject(name, tag);
    return (newGameObject);
}

std::string GameObject::GetName() const {
    return (this->_name);
}

std::string GameObject::GetTag() const {
    return (this->_tag);
}

bool GameObject::GetIsVisible() const {
    return (this->_isVisible);
}

bool GameObject::GetIsTrigger() const {
    return (this->_isTrigger);
}

int GameObject::GetLayer() const {
    return (this->_layer);
}

void GameObject::SetName(std::string newName) {
    this->_name = newName;
}

void GameObject::SetTag(std::string newTag) {
    this->_tag = newTag;
}

void GameObject::SetIsVisible(bool newIsVisible) {
    this->_isVisible = newIsVisible;
}

void GameObject::SetIsTrigger(bool newIsTrigger) {
    this->_isTrigger = newIsTrigger;
}

void GameObject::SetLayer(int newLayer) {
    if (newLayer == 0) {
        std::cerr << "[WARNING] : Layer cannot be 0. Actual layer is set to 1" << std::endl;
        this->_layer = 1;
    } else {
        this->_layer = newLayer;
    }
}

template<>
void GameObject::AddComponent<Camera>(float posX, float posY, float posZ) {
    static_assert(std::is_base_of<Component, T>::value, "[ERROR] : Constraint violation. Class must inherit from Component.");
    this->_components.insert(this->_components.end(), new Camera(posX, posY, posZ));            
}

template<>
void GameObject::AddComponent<Camera>(float posX, float posY, float posZ, float centerX, float centerY, float centerZ) {
    static_assert(std::is_base_of<Component, T>::value, "[ERROR] : Constraint violation. Class must inherit from Component.");
    this->_components.insert(this->_components.end(), new Camera(posX, posY, posZ, centerX, centerY, centerZ));            
}

template<>
void GameObject::AddComponent<Camera>(float posX, float posY, float posZ, float centerX, float centerY, float centerZ, float upX, float upY, float upZ) {
    static_assert(std::is_base_of<Component, T>::value, "[ERROR] : Constraint violation. Class must inherit from Component.");
    this->_components.insert(this->_components.end(), new Camera(posX, posY, posZ, centerX, centerY, centerZ, upX, upY, upZ));            
}
