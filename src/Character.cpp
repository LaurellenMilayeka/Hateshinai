#include "Character.hpp"

Character::Character(std::string, std::string spritesheetPath, SDL_Renderer *renderer) {

    this->_strength = 0;
    this->_power = 0;
    this->_wisdom = 0;
    this->_agility = 0;
    this->_vitality = 0;
    this->_speed = 0;
    this->_constitution = 0;
    this->_spirit = 0;

    this->_cp = 0;

    this->_characterSpriteSheet.LoadSpriteSheet(spritesheetPath);

    this->_characterSprite = SDL_CreateTextureFromSurface(renderer, this->_characterSpriteSheet.GetSpriteSheet());

    this->_characterAnimation = new Animation();

    this->_characterAnimation->StopAnimation();

    this->_pixPositionX = 0;
    this->_pixPositionY = 24;

    this->_characterDirection = DOWN;
    this->_characterState = IDLE;
}

Character::~Character() {

}

int Character::GetStrength() const {

    return (this->_strength);

}

int Character::GetPower() const {

    return (this->_power);

}

int Character::GetWisdom() const {

    return (this->_wisdom);

}

int Character::GetAgility() const {

    return (this->_agility);

}

int Character::GetVitality() const {

    return (this->_vitality);

}

int Character::GetSpeed() const {

    return (this->_speed);

}

int Character::GetConstitution() const {

    return (this->_constitution);

}

int Character::GetSpirit() const {

    return (this->_spirit);

}

int Character::GetMapPositionX() const {

    return (this->_mapPositionX);

}

int Character::GetMapPositionY() const {

    return (this->_mapPositionY);

}

void Character::SetStrength(int newStrength) {

    this->_strength = newStrength;

}

void Character::SetPower(int newPower) {

    this->_power = newPower;

}

void Character::SetWisdom(int newWisdom) {

    this->_wisdom = newWisdom;

}

void Character::SetAgility(int newAgility) {

    this->_agility = newAgility;

}

void Character::SetVitality(int newVitality) {

    this->_vitality = newVitality;

}

void Character::SetSpeed(int newSpeed) {

    this->_speed = newSpeed;

}

void Character::SetConstitution(int newConstitution) {

    this->_constitution = newConstitution;

}

void Character::SetSpirit(int newSpirit) {

    this->_spirit = newSpirit;

}

void Character::SetMapPositionX(int newPositionX) {
    
        this->_mapPositionX = newPositionX;
    
}
    
void Character::SetMapPositionY(int newPositionY) {
    
    this->_mapPositionY = newPositionY;
    
}

int Character::GetCompetencePoint() const {

    return (this->_cp);

}

void Character::SetCompetencePoint(int newCompetencePoint) {

    this->_cp = newCompetencePoint;

}

double Character::GetPixPositionX() {

    return (this->_pixPositionX);

}

double Character::GetPixPositionY() {

    return (this->_pixPositionY);

}

void Character::SetPixPositionX(double newPixPositionX) {

    this->_pixPositionX = newPixPositionX;

}

void Character::SetPixPositionY(double newPixPositionY) {

    this->_pixPositionY = newPixPositionY;

}

SDL_Texture *Character::GetCharacterSprite() const {

    return (this->_characterSprite);

}

Character::DIRECTION Character::GetDirection() const {
    return (this->_characterDirection);
}

void Character::SetDirection(DIRECTION newDirection) {
    this->_characterDirection = newDirection;
}

Character::STATE Character::GetState() const {
    return (this->_characterState);
}

void Character::SetState(STATE newState) {
    this->_characterState = newState;
}

void Character::LoadAnimation() {

}

void Character::PlayAnimation() {

    this->_characterAnimation->PlayAnimation();

}

void Character::PauseAnimation() {

    this->_characterAnimation->PauseAnimation();

}

void Character::StopAnimation() {

    this->_characterAnimation->StopAnimation();

}

Animation::ANIMATION_STATE Character::GetAnimationState() const {

    return (this->_characterAnimation->GetAnimationState());

}

void Character::SetAnimation(Animation::ANIMATION newAnimation) {
    this->_characterAnimation->SetAnimation(newAnimation);
}

void Character::StepAnimation() {

    this->_characterAnimation->Step();

}

void Character::SetAnimationSpeed() {

}

void Character::ResetAnimationSpeed() {

}

SDL_Rect *Character::GetActualFramePosition() {

    SDL_Rect *rect = this->_characterSpriteSheet.GetActualFramePosition(this->_characterAnimation->GetAnimationFrame(), this->_characterAnimation->GetAnimation());

    rect[1].x = this->_pixPositionX;
    rect[1].y = this->_pixPositionY;

    return (rect);
}