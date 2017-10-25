#include "Label.hpp"

using namespace Engine;

Label::Label(GameObject& source) : Component(source) {
    this->_updated = true;
    this->_fontInit = false;
    this->_textInit = false;
    this->_texInit = false;
}

Label::~Label() {

}

std::string Label::GetType() {
    return ("Label");
} 

std::string const& Label::GetText() const {
    return (this->_label);
}

void Label::SetText(std::string const& newLabel) {
    this->_label = newLabel;
    this->_updated = false;
    this->_textInit = true;
    this->_texInit = false;
}

void Label::Update() {
    if (this->_fontInit && this->_textInit) {
        if (!this->_updated) {
            Vector2 size;
            SDL_Surface *texSurface;
            
            size = this->_actualFont.GetSurfaceSize(this->_label);
            if ((texSurface = this->_actualFont.GetRenderSurface(this->_label)) == nullptr) {
                std::cerr << "[ERROR] : Couldn't retrieve the surface to blend." << std::endl;
            }
            this->_labelTexture.LoadTexture(texSurface);
            this->_updated = true;
            this->_texInit = true;
        }
    }
}

void Label::Render() {
    if (this->_texInit) {
        Vector2 position, scale, size;

        position = this->GetGameObject().GetComponent<Transform>().GetPosition();
        scale = this->GetGameObject().GetComponent<Transform>().GetScale();
        size = this->_actualFont.GetSurfaceSize(this->_label);
        glPushMatrix();
        glDepthMask(GL_FALSE);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
        glTranslated(position.x(), this->GetGameObject().GetLayer(), position.y());
        glScaled(scale.x(), 1, scale.y());
        this->_labelTexture.SetActive();
        glBegin(GL_QUADS);
            glTexCoord2d(0, 0);
                glVertex3d(0, -(this->GetGameObject().GetLayer()), 0);
            glTexCoord2d(1, 0);
                glVertex3d(size.x(), -(this->GetGameObject().GetLayer()), 0);
            glTexCoord2d(1, 1);
                glVertex3d(size.x(), -(this->GetGameObject().GetLayer()), size.y());
            glTexCoord2d(0, 1);
                glVertex3d(0, -(this->GetGameObject().GetLayer()), size.y());
        glEnd();
        glPopMatrix();
    }
}

void Label::SetFont(std::string const& newFont) {
    this->_actualFont.LoadFont(newFont, 37);
    this->_updated = false;
    this->_fontInit = true;
    this->_texInit = false;
}