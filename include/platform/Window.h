#pragma once

#include <string_view>

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

namespace girafarig::platform {
    class Window {
    public:
        Window(uint32_t width, uint32_t height, std::string_view title);
        ~Window();

        Window(const Window&) = delete;
        Window& operator=(const Window&) = delete;

        Window(Window&&) = delete;
        Window& operator=(Window&&) = delete;

        [[nodiscard]] bool shouldClose() const;
        [[nodiscard]] float aspectRatio() const;

        void processInput() const;
        void swapBuffers() const;
    private:
        GLFWwindow* window;
        uint32_t width;
        uint32_t height;
    };
}
