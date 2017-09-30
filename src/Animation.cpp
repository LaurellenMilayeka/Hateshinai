#include "Animation.hpp"

Animation::Animation() {

    this->_frame = 0;

    this->_state = STOPPED;
    this->_speed = DEFAULT_ANIMATION_SPEED;
    this->_actualAnimation = WALK_DOWN;

    this->_lastTime = 0;

}

Animation::~Animation() {

}

void Animation::SetAnimation(ANIMATION newAnimation) {
    this->_actualAnimation = newAnimation;
}

Animation::ANIMATION Animation::GetAnimation() const {
    return (this->_actualAnimation);
}

void Animation::PlayAnimation() {

    this->_frame = 0;
    this->_state = PLAYING;

}

void Animation::PauseAnimation() {

    this->_state = PAUSED;

}

void Animation::ResumeAnimation() {

    this->_state = PLAYING;

}

void Animation::StopAnimation() {

    this->_state = STOPPED;
    this->_frame = 0;

}

int Animation::GetAnimationFrame() const {

    return (this->_frame);

}

int Animation::GetAnimationSpeed() const {

    return (this->_speed);

}

void Animation::SetAnimationFrame(int newFrame) {

    this->_frame = newFrame;

}

Animation::ANIMATION_STATE Animation::GetAnimationState() const {

    return (this->_state);

}

void Animation::SetAnimationState(Animation::ANIMATION_STATE newState) {

    this->_state = newState;

}

void Animation::Step() {

    if (this->_state == PLAYING) {

        if (SDL_GetTicks() > (this->_lastTime + this->_speed)) {

            this->_frame += 1;

            if (this->_frame == 4) {

                this->_frame = 0;

            }

            this->_lastTime = SDL_GetTicks();

        }

    }

}