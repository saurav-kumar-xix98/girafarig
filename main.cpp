#include <glad/glad.h>

#include "GlfwContext.h"
#include "OpenGlContext.h"
#include "Window.h"

int main() {
    girafagir::GlfwContext::initialize();
    const girafagir::Window window(800, 600, "Girafagir");
    girafagir::OpenGlContext::initialize();

    while (!window.shouldClose()) {
        window.processInput();

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        window.swapBuffers();
        glfwPollEvents();
    }

    girafagir::GlfwContext::terminate();
    return 0;
}
