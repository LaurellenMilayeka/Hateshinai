#include "Input.hpp"

using namespace Engine;

Key Input::_lastFrameKey = Key::NONE;

bool Input::GetKey(Key key) {
    int state = glfwGetKey(Window::GetWindow(), key);
    if (state == GLFW_PRESS) {
        Input::_lastFrameKey = key;
        return (true);
    }
    return (false);
}

bool Input::GetKeyDown(Key key) {
    if (Input::_lastFrameKey != key && Input::GetKey(key)) {
        Input::_lastFrameKey = key;
        return (true);
    }
    return (false);
}

Key Input::GetLastKeyState() {
    return (Input::_lastFrameKey);
}

void Input::Update() {
    glfwPollEvents();
    if (Input::_lastFrameKey != Key::NONE && glfwGetKey(Window::GetWindow(), Input::_lastFrameKey) == GLFW_RELEASE) {
        Input::_lastFrameKey = Key::NONE;
    }
}