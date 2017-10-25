#include "CharacterController.hpp"

using namespace Engine;

CharacterController::CharacterController(GameObject& source) : Component(source) {
    this->_isMoving = false;
    this->_lastPosition = this->GetGameObject().GetComponent<Transform>().GetPosition();
    this->_speed = 100;
}

CharacterController::~CharacterController() {

}

std::string const CharacterController::GetType() {
    return ("CharacterController");
}

void CharacterController::MoveCharacter() {
    switch (this->_actualDirection) {
        case DIRECTION::DOWN:
            if (this->GetGameObject().GetComponent<Transform>().GetPosition().y() > (this->_lastPosition.y() - 64)) {
                this->GetGameObject().GetComponent<Transform>().Translate(Vector2::Down() * 0.10);
            } else {
                this->_isMoving = false;
                this->GetGameObject().GetComponent<Transform>().SetPosition(this->_lastPosition.x(), this->_lastPosition.y() - 64);
                this->_lastPosition = this->GetGameObject().GetComponent<Transform>().GetPosition();
            }
            break;
        case DIRECTION::UP:
            if (this->GetGameObject().GetComponent<Transform>().GetPosition().y() < (this->_lastPosition.y() + 64)) {
                this->GetGameObject().GetComponent<Transform>().Translate(Vector2::Up() * 0.10);
            } else {
                this->_isMoving = false;
                this->GetGameObject().GetComponent<Transform>().SetPosition(this->_lastPosition.x(), this->_lastPosition.y() + 64);
                this->_lastPosition = this->GetGameObject().GetComponent<Transform>().GetPosition();
            }
            break;
        case DIRECTION::LEFT:
            if (this->GetGameObject().GetComponent<Transform>().GetPosition().x() > (this->_lastPosition.x() - 64)) {
                this->GetGameObject().GetComponent<Transform>().Translate(Vector2::Left() * 0.10);
            } else {
                this->_isMoving = false;
                this->GetGameObject().GetComponent<Transform>().SetPosition(this->_lastPosition.x() - 64, this->_lastPosition.y());
                this->_lastPosition = this->GetGameObject().GetComponent<Transform>().GetPosition();
            }
            break;
        case DIRECTION::RIGHT:
            if (this->GetGameObject().GetComponent<Transform>().GetPosition().x() < (this->_lastPosition.x() + 64)) {
                this->GetGameObject().GetComponent<Transform>().Translate(Vector2::Right() * 0.10);
            } else {
                this->_isMoving = false;
                this->GetGameObject().GetComponent<Transform>().SetPosition(this->_lastPosition.x() + 64, this->_lastPosition.y());
                this->_lastPosition = this->GetGameObject().GetComponent<Transform>().GetPosition();
            }
            break;
    }
}

void CharacterController::Update() {
    if (!this->_isMoving) {
        if (Input::GetKey(Keys::W)) {
            this->_isMoving = true;
            this->_actualDirection = DIRECTION::UP;
            this->_lastPosition = this->GetGameObject().GetComponent<Transform>().GetPosition();
        } else if (Input::GetKey(Keys::A)) {
            this->_isMoving = true;
            this->_actualDirection = DIRECTION::LEFT;
            this->_lastPosition = this->GetGameObject().GetComponent<Transform>().GetPosition();
        } else if (Input::GetKey(Keys::S)) {
            this->_isMoving = true;
            this->_actualDirection = DIRECTION::DOWN;
            this->_lastPosition = this->GetGameObject().GetComponent<Transform>().GetPosition();
        } else if (Input::GetKey(Keys::D)) {
            this->_isMoving = true;
            this->_actualDirection = DIRECTION::RIGHT;
            this->_lastPosition = this->GetGameObject().GetComponent<Transform>().GetPosition();
        }
    } else {
        this->MoveCharacter();
    }
}

bool CharacterController::GetIsMoving() const {
    return (this->_isMoving);
}

DIRECTION CharacterController::GetDirection() const {
    return (this->_actualDirection);
}

void CharacterController::SetSpeed(int newSpeed) {
    this->_speed = newSpeed;
}