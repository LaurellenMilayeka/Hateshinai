#include "Core.hpp"
#include "GameState.hpp"

using namespace Engine;

Core::Core() {

}

Core::~Core() {

}

void Core::Init() {
    int result, flags;

    flags = IMG_INIT_PNG;
    glewExperimental = GL_TRUE;
    glewInit();
    result = IMG_Init(IMG_INIT_PNG); 
    TTF_Init();
    glfwInit();    
    
    if ((result&flags) != flags) {
        std::cerr << "[ERROR] : Couldn't initialize core engine." << std::endl;
        std::cerr << "[INFO] : Error : " << IMG_GetError() << std::endl;
    }

}

void Core::Run() {
    this->_window.CreateWindow("Default name", 1280, 768);

    glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(70, (double)1280/768, 1, 2000);
	glEnable(GL_TEXTURE_2D);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_MODELVIEW);
    //gluLookAt(0,-547,0,0,0,0,0,0,1);

    glEnable(GL_TEXTURE_2D);
    glEnable(GL_DEPTH_TEST);
}

void Core::Start() {

}

void Core::Update() {
    Input::Update();    
    this->_states.top()->Update();
}

void Core::Render() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);    
    this->_states.top()->Render();
    this->_window.RefreshDisplay();    
}

void Core::AddGameState(GameState* toAdd) {
    this->_states.push(toAdd);
}

std::stack<GameState*> const& Core::GetStates() const {
    return (this->_states);
}

Window const& Core::GetWindow() const {
    return (this->_window);
}

bool Core::IsRunning() {
    return (!this->_window.Quit());
}