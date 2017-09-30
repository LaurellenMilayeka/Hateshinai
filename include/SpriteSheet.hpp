#pragma once

#include <iostream>
#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class SpriteSheet {

	SDL_Surface *_spritesheet;
	size_t _width;
	size_t _height;
	size_t _caseWidth;
	size_t _caseHeight;

	int _actualFrame;
	unsigned int _animationTime;
	unsigned int _oldTime;

public:

	SpriteSheet();
	~SpriteSheet();

	SDL_Surface *GetSpriteSheet() const;

	size_t GetWidth() const;
	size_t GetHeight() const;

	size_t GetCaseWidth() const;
	size_t GetCaseHeight() const;

	void LoadSpriteSheet(std::string filename);
	SDL_Rect *GetActualFramePosition(int, int);
	void StepAnimation();
};

