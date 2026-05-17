#include "Window.h"

#include <iostream>
#include <stdexcept>

#include <glad/glad.h>

namespace {
    void framebufferSizeCallback(GLFWwindow* window, int width, int height);
}

girafarig::Window::Window(const int width, const int height, const std::string_view title) {
    window = glfwCreateWindow(width, height, title.data(), nullptr, nullptr);
    if (window == nullptr) {
        std::cout << "Failed to create GLFW window" << std::endl;
        throw std::runtime_error("Failed to create GLFW window");
    }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);
}

girafarig::Window::~Window() {
    glfwDestroyWindow(window);
}

bool girafarig::Window::shouldClose() const {
    return glfwWindowShouldClose(window);
}

void girafarig::Window::processInput() const {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
}

void girafarig::Window::swapBuffers() const {
    glfwSwapBuffers(window);
}

namespace {
    void framebufferSizeCallback(GLFWwindow* window, const int width, const int height) {
        glViewport(0, 0, width, height);
    }
}
