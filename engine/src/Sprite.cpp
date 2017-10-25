#include "Sprite.hpp"

using namespace Engine;

Sprite::Sprite(GameObject& source) : Component(source) {

}

Sprite::~Sprite() {

}

std::string const Sprite::GetType() {
    return ("Sprite");
}

void Sprite::Update() {
    if (this->GetGameObject().CheckComponent<CharacterController>()) {
        if (this->GetGameObject().GetComponent<CharacterController>().GetIsMoving()) {
            this->GetGameObject().GetComponent<CharacterAnimator>().PlayAnimation();
            switch (this->GetGameObject().GetComponent<CharacterController>().GetDirection()) {
                case DIRECTION::UP:
                    this->GetGameObject().GetComponent<CharacterAnimator>().SetAnimation(ANIMATION::WALK_UP);
                    break;
                case DIRECTION::DOWN:
                    this->GetGameObject().GetComponent<CharacterAnimator>().SetAnimation(ANIMATION::WALK_DOWN);
                    break;
                case DIRECTION::LEFT:
                    this->GetGameObject().GetComponent<CharacterAnimator>().SetAnimation(ANIMATION::WALK_LEFT);
                    break;
                case DIRECTION::RIGHT:
                    this->GetGameObject().GetComponent<CharacterAnimator>().SetAnimation(ANIMATION::WALK_RIGHT);
                    break;
            }
        } else if (Input::GetLastKeyState() == Key::NONE) {
            this->GetGameObject().GetComponent<CharacterAnimator>().StopAnimation();
        }
    }
}

void Sprite::Render() {
    if (this->GetGameObject().GetIsVisible()) {
        Vector2 position, scale;

        glPushMatrix();
        position = this->GetGameObject().GetComponent<Transform>().GetPosition();
        scale = this->GetGameObject().GetComponent<Transform>().GetScale();
        this->_spriteTex.SetActive();
        glDepthMask(GL_FALSE);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
        gluLookAt(0, -548, 0, 0, 0, 0, 0, 0, 1);
        //gluLookAt(position.x(), -548, position.y(), position.x(), 0, position.y(), 0, 0, 1);
        glScaled(scale.x(), 1, scale.y());
        glTranslated(position.x(), this->GetGameObject().GetLayer() / 10, position.y());
        glBegin(GL_QUADS);
            if (this->GetGameObject().CheckComponent<CharacterAnimator>()) {
                glTexCoord2d(0 + (this->GetGameObject().GetComponent<CharacterAnimator>().GetFrame() * 0.25), 0 + (this->GetGameObject().GetComponent<CharacterAnimator>().GetAnimation() * 0.25));
                    glVertex3d(0, 0, 0);
                glTexCoord2d(0 + (this->GetGameObject().GetComponent<CharacterAnimator>().GetFrame() * 0.25), 0 + (this->GetGameObject().GetComponent<CharacterAnimator>().GetAnimation() * 0.25) + 0.25);
                    glVertex3d(0, 0, this->GetGameObject().GetComponent<CharacterAnimator>().GetFrameHeight());
                glTexCoord2d(0 + (this->GetGameObject().GetComponent<CharacterAnimator>().GetFrame() * 0.25) + 0.25, 0 + (this->GetGameObject().GetComponent<CharacterAnimator>().GetAnimation() * 0.25) + 0.25);
                    glVertex3d(this->GetGameObject().GetComponent<CharacterAnimator>().GetFrameWidth(), 0, this->GetGameObject().GetComponent<CharacterAnimator>().GetFrameHeight());
                glTexCoord2d(0 + (this->GetGameObject().GetComponent<CharacterAnimator>().GetFrame() * 0.25) + 0.25, 0 + (this->GetGameObject().GetComponent<CharacterAnimator>().GetAnimation() * 0.25));
                    glVertex3d(this->GetGameObject().GetComponent<CharacterAnimator>().GetFrameWidth(), 0, 0);
            } else {
                glTexCoord2d(0, 0);
                    glVertex3d(-1 * (this->_spriteTex.GetTexWidth() / 2), 0, -1 * (this->_spriteTex.GetTexHeight() / 2));
                glTexCoord2d(0, 1);
                    glVertex3d(-1 * (this->_spriteTex.GetTexWidth() / 2), 0, 1 * (this->_spriteTex.GetTexHeight() / 2));
                glTexCoord2d(1, 1);
                    glVertex3d(1 * (this->_spriteTex.GetTexWidth() / 2), 0, 1 * (this->_spriteTex.GetTexHeight() / 2));
                glTexCoord2d(1, 0);
                    glVertex3d(1 * (this->_spriteTex.GetTexWidth() / 2), 0, -1 * (this->_spriteTex.GetTexHeight() / 2));
            }
        glEnd();
        glDisable(GL_BLEND);
        glDepthMask(GL_TRUE);
        glPopMatrix();
    }
}

void Sprite::SetTexture(std::string const &texPath) {
    this->_spriteTex.LoadTexture(texPath);
}

void Sprite::SetTexture(Texture const& newTexture) {
    this->_spriteTex = newTexture;
}