#include "WorldState.hpp"

WorldState::WorldState(SDL_Renderer *renderer) {
    
    this->_renderer = renderer;
    
    this->_pos = new SDL_Rect();

    this->_player = new Character("Template", "data/tests/template1.png", this->_renderer);

    this->_worldMap = new Map("data/tests/map1.png");

    this->_dirKeyDown = false;
    
}

WorldState::~WorldState() {

}

void WorldState::InitState() {

    SDL_Surface *worldMap = this->_worldMap->GetMap().GetSpriteSheet();

    /*if ((worldMap = IMG_Load("data/tests/map1.png")) == nullptr) {

        std::cerr << "Error loading map" << std::endl << IMG_GetError() << std::endl;
        exit(EXIT_FAILURE);

    }*/

    this->_texMap = SDL_CreateTextureFromSurface(this->_renderer, worldMap);

    SDL_FreeSurface(worldMap);
}

void WorldState::Update() {

    if (this->_player->GetState() == Character::IDLE) {
        
        this->_player->StopAnimation();
        
    }
        
    if (this->_player->GetState() == Character::MOVING) {

        static int _charPositionX = this->_player->GetPixPositionX();
        static int _charPositionY = this->_player->GetPixPositionY();

        if (this->_player->GetDirection() == Character::DOWN) {
            
            this->_player->SetPixPositionY(this->_player->GetPixPositionY() + 3.6);

            if (this->_player->GetPixPositionY() >= (_charPositionY + HEIGHT_MAP_CASE)) {

                this->_player->SetPixPositionY((int)(this->_player->GetPixPositionY() / HEIGHT_MAP_CASE) * HEIGHT_MAP_CASE + 24);

                _charPositionY = this->_player->GetPixPositionY();

                if (!this->_dirKeyDown) {
                    
                   this->_player->SetState(Character::IDLE);
                    
                }        
            }
        }
        else if (this->_player->GetDirection() == Character::UP) {
            
            this->_player->SetPixPositionY(this->_player->GetPixPositionY() - 3.6);

            if (this->_player->GetPixPositionY() <= (_charPositionY - HEIGHT_MAP_CASE)) {

                this->_player->SetPixPositionY((int)((this->_player->GetPixPositionY() / HEIGHT_MAP_CASE) + 1) * HEIGHT_MAP_CASE - 36);

                _charPositionY = this->_player->GetPixPositionY();

                if (!this->_dirKeyDown) {
                    
                   this->_player->SetState(Character::IDLE);
                    
                }        
            }
        }
        else if (this->_player->GetDirection() == Character::LEFT) {
            
            this->_player->SetPixPositionX(this->_player->GetPixPositionX() - 3.6);

            if (this->_player->GetPixPositionX() <= (_charPositionX - WIDTH_MAP_CASE)) {

                this->_player->SetPixPositionX((int)((this->_player->GetPixPositionX() / WIDTH_MAP_CASE) + 1) * WIDTH_MAP_CASE);

                _charPositionX = this->_player->GetPixPositionX();

                if (!this->_dirKeyDown) {
                    
                   this->_player->SetState(Character::IDLE);
                    
                }
            }
        }
        else if (this->_player->GetDirection() == Character::RIGHT) {
            
            this->_player->SetPixPositionX(this->_player->GetPixPositionX() + 3.6);

            if (this->_player->GetPixPositionX() >= (_charPositionX + WIDTH_MAP_CASE)) {

                this->_player->SetPixPositionX((int)(this->_player->GetPixPositionX() / WIDTH_MAP_CASE) * WIDTH_MAP_CASE);

                _charPositionX = this->_player->GetPixPositionX();

                if (!this->_dirKeyDown) {
                    
                   this->_player->SetState(Character::IDLE);
                    
                }
            }
        }            
    }

    this->_pos = this->_player->GetActualFramePosition();

    if (this->_player->GetAnimationState() == Animation::PLAYING) {
    
        this->_player->StepAnimation();
    
    }
    
}

void WorldState::Draw() {

    SDL_SetRenderDrawColor(this->_renderer, 0, 0, 0, 255);
    
    SDL_RenderClear(this->_renderer);

    SDL_RenderCopy(this->_renderer, this->_texMap, NULL, NULL);
    SDL_RenderCopy(this->_renderer, this->_player->GetCharacterSprite(), &(this->_pos[0]), &(this->_pos[1]));

    SDL_RenderPresent(this->_renderer);
    delete(this->_pos);

}

void WorldState::HandleEvent(SDL_Event event) {

    switch (event.type) {
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym) {
                case SDLK_DOWN:

                    if (this->_player->GetState() == Character::IDLE) {

                        this->_player->SetAnimation(Animation::WALK_DOWN);
                        this->_player->SetDirection(Character::DOWN);
                        this->_player->SetState(Character::MOVING);

                        if (this->_player->GetAnimationState() != Animation::PLAYING) {

                            this->_player->PlayAnimation();

                        }

                        this->_dirKeyDown = true;

                    }

                    break;
                case SDLK_UP:

                    if (this->_player->GetState() == Character::IDLE) {

                        this->_player->SetAnimation(Animation::WALK_UP);
                        this->_player->SetDirection(Character::UP);
                        this->_player->SetState(Character::MOVING);

                        if (this->_player->GetAnimationState() != Animation::PLAYING) {
                            
                            this->_player->PlayAnimation();
                            
                        }
                            
                        this->_dirKeyDown = true;

                    }

                    break;
                case SDLK_LEFT:

                    if (this->_player->GetState() == Character::IDLE) {

                        this->_player->SetAnimation(Animation::WALK_LEFT);
                        this->_player->SetDirection(Character::LEFT);
                        this->_player->SetState(Character::MOVING);

                        if (this->_player->GetAnimationState() != Animation::PLAYING) {
                            
                            this->_player->PlayAnimation();
                            
                        }
                            
                        this->_dirKeyDown = true;

                    }

                    break;
                case SDLK_RIGHT:

                    if (this->_player->GetState() == Character::IDLE) {

                        this->_player->SetAnimation(Animation::WALK_RIGHT);
                        this->_player->SetDirection(Character::RIGHT);
                        this->_player->SetState(Character::MOVING);
                        if (this->_player->GetAnimationState() != Animation::PLAYING) {
                            
                            this->_player->PlayAnimation();
                            
                        }
                            
                        this->_dirKeyDown = true;

                    }

                    break;
            }
            break;
        case SDL_KEYUP:
            this->_dirKeyDown = false;
            break;
    }

}

void WorldState::UnloadState() {

    SDL_DestroyTexture(this->_texMap);

}

void WorldState::ChangeState() {

    this->UnloadState();

}