#include "Time.hpp"

using namespace Engine;

int Time::_lastTime = (int)(glfwGetTime() * 1000);

int Time::GetTime() {
    return ((int)(glfwGetTime() * 1000));
}

double Time::GetLastFrameTime() {
    int actualTime = (int)(glfwGetTime() * 1000);
    int elapsedTime = actualTime - Time::_lastTime;
    Time::_lastTime = (int)(glfwGetTime() * 1000);
    return (elapsedTime + 0.1);
}
