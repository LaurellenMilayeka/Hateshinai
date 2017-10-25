#include "Vector2.hpp"

using namespace Engine;

Vector2::Vector2() {
    this->_x = 0;
    this->_y = 0;
}

Vector2::Vector2(double x, double y) {
    this->_x = x;
    this->_y = y;
}

Vector2::~Vector2() {
    
}

double Vector2::x() const {
    return (this->_x);
}

double Vector2::y() const {
    return (this->_y);
}


Vector2 Vector2::Up() {
    return (Vector2(0, 1));
}

Vector2 Vector2::Down() {
    return (Vector2(0, -1));
}

Vector2 Vector2::Right() {
    return (Vector2(1, 0));
}

Vector2 Vector2::Left() {
    return (Vector2(-1, 0));
}


Vector2& Vector2::operator=(Vector2 const &oldVector) {
    this->_x = oldVector.x();
    this->_y = oldVector.y();
    return (*this);
}

Vector2& Vector2::operator+=(Vector2 const &oldVector) {
    this->_x += oldVector.x();
    this->_y += oldVector.y();
    return (*this);
}

Vector2& Vector2::operator*(double const nb) {
    this->_x *= nb;
    this->_y *= nb;
    return (*this);
}