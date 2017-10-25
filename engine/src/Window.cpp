#include "Window.hpp"

using namespace Engine;

GLFWwindow *Window::_window = nullptr;

Window::Window() {

}

void Window::CreateWindow(std::string const& windowName, size_t width, size_t height, bool isCurrentContext) {
    Window::_window = glfwCreateWindow(width, height, windowName.c_str(), NULL, NULL);
    if (!Window::_window) {
        std::cerr << "An error occured" << std::endl;
    }
    if (isCurrentContext) {
        glfwMakeContextCurrent(Window::_window);
    }
    this->_windowName = windowName;
    this->_windowHeight = height;
    this->_windowWidth = width;
    this->_isCurrentContext = isCurrentContext;
}

size_t Window::GetWindowHeight() {
    return (this->_windowHeight);
}

size_t Window::GetWindowWidth() {
    return (this->_windowWidth);
}

std::string Window::GetWindowName() {
    return (this->_windowName);
}

void Window::SetActiveContext() {
    glfwMakeContextCurrent(Window::_window);    
}

bool Window::Quit() {
    return (glfwWindowShouldClose(Window::_window));
}

void Window::RefreshDisplay() {
    glfwSwapBuffers(Window::_window);
}

GLFWwindow* Window::GetWindow() {
    return (Window::_window);
}

void Window::SetTitle(std::string newWindowName) {
    glfwSetWindowTitle(Window::_window, newWindowName.c_str());
    this->_windowName = newWindowName;
}