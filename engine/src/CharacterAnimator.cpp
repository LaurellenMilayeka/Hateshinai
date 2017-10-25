#include "CharacterAnimator.hpp"

using namespace Engine;

CharacterAnimator::CharacterAnimator(GameObject& source) : Component(source) {
    this->_frameWidth = 0;
    this->_frameHeight = 0;
    this->_nbFrames = 0;
    this->_actualAnim = ANIMATION::WALK_DOWN;
    this->_frame = 0;
    this->_animationSpeed = 164;
}

CharacterAnimator::~CharacterAnimator() {

}

std::string const CharacterAnimator::GetType() {
    return ("CharacterAnimator");
}

void CharacterAnimator::Update() {
    if (this->_animPlaying) {
        if (Time::GetTime() > (this->_lastTime + this->_animationSpeed)) {
            this->_frame++;
            if (this->_frame == 4) {
                this->_frame = 0;
            }
            this->_lastTime = Time::GetTime();
        }
    }
}

int CharacterAnimator::GetFrameWidth() const {
    return (this->_frameWidth);
}

int CharacterAnimator::GetFrameHeight() const {
    return (this->_frameHeight);
}

int CharacterAnimator::GetNbFrames() const {
    return (this->_nbFrames);
}

ANIMATION CharacterAnimator::GetAnimation() const {
    return (this->_actualAnim);
}

int CharacterAnimator::GetFrame() const {
    return (this->_frame);
}

void CharacterAnimator::SetFrameWidth(int newWidth) {
    this->_frameWidth = newWidth;
}

void CharacterAnimator::SetFrameHeight(int newHeight) {
    this->_frameHeight = newHeight;
}

void CharacterAnimator::SetNbFrames(int newNbFrames) {
    this->_nbFrames = newNbFrames;
}

void CharacterAnimator::SetAnimation(ANIMATION newAnimation) {
    this->_actualAnim = newAnimation;
}

void CharacterAnimator::SetAnimationSpeed(int newAnimationSpeed) {
    this->_animationSpeed = newAnimationSpeed;
}

void CharacterAnimator::PlayAnimation() {
    this->_animPlaying = true;
}

void CharacterAnimator::PauseAnimation() {
    this->_animPlaying = false;
}

void CharacterAnimator::StopAnimation() {
    this->_animPlaying = false;
    this->_frame = 0;
}