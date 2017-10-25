#include "Transform.hpp"

using namespace Engine;

Transform::Transform(GameObject& source) : Component(source) {
    this->Translate(Vector2(0.0, 0.0));
    this->SetScale(Vector2(1.0, 1.0));
}

Transform::~Transform() {

}

std::string const Transform::GetType() {
    return ("Transform");
}

Vector2 const& Transform::GetPosition() const {
    return (this->_position);
}

Vector2 const& Transform::GetScale() const {
    return (this->_scale);
}

void Transform::SetPosition(Vector2 const& newPosition) {
    this->_position = newPosition;
}

void Transform::SetPosition(double x, double y) {
    this->_position = Vector2(x, y);
}

void Transform::Translate(Vector2 const& newPosition) {
    this->_position += newPosition;
}

void Transform::MoveTowards(Vector2 const& newPosition) {
    this->_destination = newPosition;
}

void Transform::SetScale(Vector2 const& newScale) {
    this->_scale = newScale;
}

void Transform::Update() {

}

void Transform::Render() {

}