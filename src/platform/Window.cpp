#include "platform/Window.h"

#include <iostream>

#include "glad/glad.h"

namespace {
    void framebufferSizeCallback(GLFWwindow* window, int width, int height);
}

girafarig::platform::Window::Window(const uint32_t width, const uint32_t height, const std::string_view title)
    : width(width), height(height) {
    window = glfwCreateWindow(width, height, title.data(), nullptr, nullptr);
    if (window == nullptr) {
        std::cout << "Failed to create GLFW window" << std::endl;
        throw std::runtime_error("Failed to create GLFW window");
    }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);
}

girafarig::platform::Window::~Window() {
    glfwDestroyWindow(window);
}

bool girafarig::platform::Window::shouldClose() const {
    return glfwWindowShouldClose(window);
}

float girafarig::platform::Window::aspectRatio() const {
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);

    return static_cast<float>(width) / static_cast<float>(height);
}

void girafarig::platform::Window::processInput() const {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
}

void girafarig::platform::Window::swapBuffers() const {
    glfwSwapBuffers(window);
}

namespace {
    void framebufferSizeCallback(GLFWwindow* window, const int width, const int height) {
        glViewport(0, 0, width, height);
    }
}
