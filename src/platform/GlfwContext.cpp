#include "platform/GlfwContext.h"

#include <GLFW/glfw3.h>

void girafarig::platform::GlfwContext::initialize() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

void girafarig::platform::GlfwContext::terminate() {
    glfwTerminate();
}
