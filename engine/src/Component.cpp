#include "Component.hpp"

using namespace Engine;

Component::Component(GameObject& source) {
    this->_source = &source;
}

GameObject& Component::GetGameObject() const {
    return (*(this->_source));
}
