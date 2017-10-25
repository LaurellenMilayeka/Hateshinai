#pragma once

#include "Engine.hpp"
#include "Vector2.hpp"

namespace Engine {

    class Font {

        private:

            TTF_Font *_font;
            std::string _fontName;
            unsigned int _fontSize;

        public:

            Font();
            ~Font();

            void LoadFont(std::string const&, unsigned int);

            void SetFontSize(unsigned int);

            unsigned int GetFontSize() const;
            TTF_Font *GetFont() const;

            SDL_Surface *GetRenderSurface(std::string const&);
            Vector2 GetSurfaceSize(std::string const&);
    };
};