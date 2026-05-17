#include <glad/glad.h>

#include "GlfwContext.h"
#include "OpenGlContext.h"
#include "ShaderProgram.h"
#include "Window.h"

int main() {
    girafarig::GlfwContext::initialize();
    const girafarig::Window window(800, 600, "Girafagir");
    girafarig::OpenGlContext::initialize();

    girafarig::ShaderProgram shaderProgram("./resource/shader/VertexShader.glsl", "./resource/shader/FragmentShader.glsl");

    while (!window.shouldClose()) {
        window.processInput();

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        window.swapBuffers();
        glfwPollEvents();
    }

    girafarig::GlfwContext::terminate();
    return 0;
}
