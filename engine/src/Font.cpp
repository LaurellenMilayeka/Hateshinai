#include "Font.hpp"

using namespace Engine;

Font::Font() {
    this->_fontSize = 0;
    this->_fontName = "";
    this->_font = nullptr;
}

Font::~Font() {

}

void Font::LoadFont(std::string const& fontName, unsigned int fontSize) {
    if (this->_font != nullptr) {
        TTF_CloseFont(this->_font);
        this->_font = nullptr;
    }
    if ((this->_font = TTF_OpenFont(fontName.c_str(), fontSize)) == NULL) {
        std::cerr << "[ERROR] : Couldn't open font file." << std::endl;
        std::cerr << "[INFO] : Error : " << TTF_GetError() << std::endl;
    }
    this->_fontSize = fontSize;
    this->_fontName = fontName;
}

unsigned int Font::GetFontSize() const {
    return (this->_fontSize);
}

TTF_Font *Font::GetFont() const {
    return (this->_font);
}

void Font::SetFontSize(unsigned int newSize) {
    TTF_CloseFont(this->_font);
    this->_font = nullptr;
    if ((this->_font = TTF_OpenFont(this->_fontName.c_str(), newSize)) == nullptr) {
        std::cerr << "[ERROR] : Couldn't set new font size." << std::endl;
        std::cerr << "[INFO] : Error : " << TTF_GetError() << std::endl;
    }
    this->_fontSize = newSize;
}

SDL_Surface *Font::GetRenderSurface(std::string const& text) {
    return (TTF_RenderUTF8_Solid(this->_font, text.c_str(), {0, 0, 0, 0}));
}

Vector2 Font::GetSurfaceSize(std::string const& text) {
    int x, y;

    if (TTF_SizeText(this->_font, text.c_str(), &x, &y)) {
        std::cerr << "[ERROR] : String can't be rendered." << std::endl;
        std::cerr << "[INFO] : Error : " << TTF_GetError() << std::endl;
    }
    return (Vector2((double)x, (double)y));
}