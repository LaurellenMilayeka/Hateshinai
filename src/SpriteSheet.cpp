#include "SpriteSheet.hpp"

SpriteSheet::SpriteSheet() {

	this->_spritesheet = nullptr;
	this->_height = 0;
	this->_width = 0;
	this->_caseHeight = 0;
	this->_caseWidth = 0;
	this->_actualFrame = 0;
	this->_animationTime = 264;
	this->_oldTime = 0;

}


SpriteSheet::~SpriteSheet() {

}

SDL_Surface *SpriteSheet::GetSpriteSheet() const {

	return (this->_spritesheet);

}

size_t SpriteSheet::GetWidth() const {

	return (this->_width);

}

size_t SpriteSheet::GetHeight() const {

	return (this->_height);

}

size_t SpriteSheet::GetCaseHeight() const {

	return (this->_caseHeight);

}

size_t SpriteSheet::GetCaseWidth() const {

	return (this->_caseWidth);

}

SDL_Rect *SpriteSheet::GetActualFramePosition(int frame, int animation) {

	SDL_Rect *pos;

	if ((pos = (SDL_Rect*)malloc(sizeof(SDL_Rect) * 2)) == nullptr) {

		std::cerr << "Could not allocate SDL_Rect resource in memory" << std::endl;

		exit(EXIT_FAILURE);

	}

	pos[0].x = (this->_caseWidth * frame);
	pos[0].y = (this->_caseHeight * animation);
	pos[0].w = (this->_caseWidth);
	pos[0].h = (this->_caseHeight);

	pos[1].x = 0;
	pos[1].y = 24;
	pos[1].w = this->_caseWidth;
	pos[1].h = this->_caseHeight;

	return (pos);

}

void SpriteSheet::LoadSpriteSheet(std::string name) {

	if ((this->_spritesheet = IMG_Load(name.c_str())) == nullptr) {
	
		std::cout << "Error while loading image" << std::endl << IMG_GetError() << std::endl;
		exit(EXIT_FAILURE);
	
	}

	this->_width = this->_spritesheet->w;
	this->_height = this->_spritesheet->h;
	this->_caseHeight = this->_height / 4;
	this->_caseWidth = this->_width / 4;

}
