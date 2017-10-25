#include <cstring>
#include "Texture.hpp"

using namespace Engine;

Texture::Texture() {
    
}

Texture::Texture(std::string const& texPath) {
    this->LoadTexture(texPath);
}

Texture::Texture(unsigned char* texData, int width, int height) {
    this->LoadTexture(texData, width, height);
}

Texture::~Texture() {
    //std::cout << "Destructed" << std::endl;
    //glDeleteTextures(1, &(this->_textureID));
}

SDL_Surface *Texture::FlipSurface(SDL_Surface *surface) {
    int line, pitch;
    SDL_Surface *flippedSurface = SDL_CreateRGBSurface(SDL_SWSURFACE, surface->w, surface->h, surface->format->BitsPerPixel,
                                                        surface->format->Rmask, surface->format->Gmask, surface->format->Bmask, surface->format->Amask);

    SDL_LockSurface(surface);
    SDL_LockSurface(flippedSurface);
    pitch = surface->pitch;
    for (line = 0; line < surface->h; line++) {
        std::memcpy(&((unsigned char *)flippedSurface->pixels)[line * pitch], &((unsigned char *)surface->pixels)[(surface->h - 1 - line) * pitch], pitch);
    }
    SDL_UnlockSurface(surface);
    SDL_UnlockSurface(flippedSurface);
    return (flippedSurface);
}

void Texture::LoadTexture(std::string const& texPath) {

    SDL_Surface *texture = nullptr, *newFormatTexture = nullptr, *flippedTexture = nullptr;
    SDL_PixelFormat tmpFormat;
    Uint32 amask, rmask, gmask, bmask;

#if SDL_BYTEORDER == SDL_BIG_ENDIAN

    rmask = 0xFF000000;
    gmask = 0x00FF0000;
    bmask = 0x0000FF00;
    amask = 0x000000FF;

#else

    rmask = 0x000000FF;
    gmask = 0x0000FF00;
    bmask = 0x00FF0000;
    amask = 0xFF000000;

#endif

    if ((texture = IMG_Load(texPath.c_str())) == nullptr) {
        std::cerr << "[ERROR] : Could not load texture " << texPath << ". Skipping..." << std::endl;
    }
    tmpFormat = *(texture->format);
    tmpFormat.BitsPerPixel = 32;
    tmpFormat.BytesPerPixel = 4;
    tmpFormat.Rmask = rmask;
    tmpFormat.Gmask = gmask;
    tmpFormat.Bmask = bmask;
    tmpFormat.Amask = amask;
    if ((newFormatTexture = SDL_ConvertSurface(texture, &tmpFormat, SDL_SWSURFACE)) == nullptr)  {
        std::cerr << "[ERROR] : Couldn't convert surface to given format." << std::endl;
    }
    if ((flippedTexture = this->FlipSurface(newFormatTexture)) == nullptr) {
        std::cerr << "[ERROR] : Couldn't flip surface." << std::endl;
    }
    glGenTextures(1, &(this->_textureID));
    glBindTexture(GL_TEXTURE_2D, this->_textureID);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, flippedTexture->w, flippedTexture->h, 0, GL_RGBA, GL_UNSIGNED_BYTE, flippedTexture->pixels);
    glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_WIDTH, &(this->_width));
    glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_HEIGHT, &(this->_height));
    this->_depth = 0;
    //glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_DEPTH, &(this->_depth));
    glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_INTERNAL_FORMAT, &(this->_format));
    glBindTexture(GL_TEXTURE_2D, 0);
    SDL_FreeSurface(flippedTexture);
    SDL_FreeSurface(newFormatTexture);
    SDL_FreeSurface(texture);

}

void Texture::LoadTexture(SDL_Surface *surface) {
    SDL_Surface *newFormatTexture = nullptr, *flippedTexture = nullptr;
    SDL_PixelFormat tmpFormat;
    Uint32 amask, rmask, gmask, bmask;

    #if SDL_BYTEORDER == SDL_BIG_ENDIAN
    
        rmask = 0xFF000000;
        gmask = 0x00FF0000;
        bmask = 0x0000FF00;
        amask = 0x000000FF;
    
    #else
    
        rmask = 0x000000FF;
        gmask = 0x0000FF00;
        bmask = 0x00FF0000;
        amask = 0xFF000000;
    
    #endif
        
    tmpFormat = *(surface->format);
    tmpFormat.BitsPerPixel = 32;
    tmpFormat.BytesPerPixel = 4;
    tmpFormat.Rmask = rmask;
    tmpFormat.Gmask = gmask;
    tmpFormat.Bmask = bmask;
    tmpFormat.Amask = amask;
    if ((newFormatTexture = SDL_ConvertSurface(surface, &tmpFormat, SDL_SWSURFACE)) == nullptr)  {
        std::cerr << "[ERROR] : Couldn't convert surface to given format." << std::endl;
    }
    if ((flippedTexture = this->FlipSurface(newFormatTexture)) == nullptr) {
        std::cerr << "[ERROR] : Couldn't flip surface." << std::endl;
    }
    glGenTextures(1, &(this->_textureID));
    glBindTexture(GL_TEXTURE_2D, this->_textureID);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, flippedTexture->w, flippedTexture->h, 0, GL_RGBA, GL_UNSIGNED_BYTE, flippedTexture->pixels);
    glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_WIDTH, &(this->_width));
    glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_HEIGHT, &(this->_height));
    this->_depth = 0;
    //glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_DEPTH, &(this->_depth));
    glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_INTERNAL_FORMAT, &(this->_format));
    glBindTexture(GL_TEXTURE_2D, 0);
    SDL_FreeSurface(flippedTexture);
    SDL_FreeSurface(newFormatTexture);
}

void Texture::LoadTexture(unsigned char *texData, int width, int height) {
    glGenTextures(1, &(this->_textureID));
    glBindTexture(GL_TEXTURE_2D, this->_textureID);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_LUMINANCE_ALPHA, GL_UNSIGNED_BYTE, texData);
    glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_INTERNAL_FORMAT, &(this->_format));
    glBindTexture(GL_TEXTURE_2D, 0);
    this->_width = width;
    this->_height = height;
}

void Texture::SetTexture(unsigned int newTexture) {
    this->_textureID = newTexture;
}

void Texture::SetTexHeight(int newHeight) {
    this->_height = newHeight;
}

void Texture::SetTexWidth(int newWidth) {
    this->_width = newWidth;
}

void Texture::SetTexDepth(int newDepth) {
    this->_depth = newDepth;
}

void Texture::SetTexFormat(int newFormat) {
    this->_format = newFormat;
}

unsigned int Texture::GetTexture() const {
    return (this->_textureID);
}

void Texture::SetActive() {
    glBindTexture(GL_TEXTURE_2D, this->_textureID);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
}

int Texture::GetTexHeight() const {
    return (this->_height);
}

int Texture::GetTexWidth() const {
    return (this->_width);
}

int Texture::GetTexDepth() const {
    return (this->_depth);
}

int Texture::GetTexFormat() const {
    return (this->_format);
}

Texture& Texture::operator=(Texture const& oldTexture) {
    if (this != &oldTexture) {
        this->_textureID = oldTexture._textureID;
        this->_width = oldTexture.GetTexWidth();
        this->_height = oldTexture.GetTexHeight();
        this->_format = oldTexture.GetTexFormat();
        this->_depth = oldTexture.GetTexDepth();
    }
    /*this->_textureID = oldTexture.GetTexture();*/
    return (*this);
}