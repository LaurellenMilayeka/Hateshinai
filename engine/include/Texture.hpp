#pragma once

#include "Engine.hpp"

namespace Engine {

    class Texture {

    private:

        GLuint _textureID;
        
        GLint _height;
        GLint _width;
        GLint _depth;
        GLint _format;

        SDL_Surface *FlipSurface(SDL_Surface*);

        void SetTexture(unsigned int);

        void SetTexHeight(int);
        void SetTexWidth(int);
        void SetTexDepth(int);
        void SetTexFormat(int);

    public:
        
        Texture();
        Texture(std::string const&);
        Texture(unsigned char *, int, int);
        ~Texture();

        void LoadTexture(std::string const&);
        void LoadTexture(SDL_Surface *);
        void LoadTexture(unsigned char*, int, int);

        unsigned int GetTexture() const;

        int GetTexHeight() const;
        int GetTexWidth() const;
        int GetTexDepth() const;
        int GetTexFormat() const;

        void SetActive();

        //Texture& operator=(Texture&&);
        Texture& operator=(Texture const&);
    };
};