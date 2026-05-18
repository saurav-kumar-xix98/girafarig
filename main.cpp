#include <vector>

#include "graphics/buffer/IndexBuffer.h"
#include "graphics/buffer/VertexArray.h"
#include "graphics/buffer/VertexBuffer.h"
#include "graphics/context/OpenGlContext.h"
#include "graphics/shader/ShaderProgram.h"
#include "graphics/Vertex.h"
#include "platform/GlfwContext.h"
#include "platform/Window.h"

#include <glad/glad.h>

int main() {
    girafarig::platform::GlfwContext::initialize();
    const girafarig::platform::Window window(800, 600, "Girafarig");
    girafarig::graphics::context::OpenGlContext::initialize();

    const girafarig::graphics::shader::ShaderProgram shaderProgram("./resource/shader/VertexShader.glsl", "./resource/shader/FragmentShader.glsl");
    shaderProgram.useProgram();
    shaderProgram.setUniform("uColor", {1.0f, 0.0f, 0.0f, 1.0f});

    const std::vector<girafarig::Vertex> vertices = {
        { 0.5f,  0.5f, 0.0f},
        { 0.5f, -0.5f, 0.0f},
        {-0.5f, -0.5f, 0.0f},
        {-0.5f,  0.5f, 0.0f}
    };

    const std::vector<unsigned int> indices = {
        0, 1, 3,
        1, 2, 3
    };

    const girafarig::graphics::buffer::VertexArray vertexArray;
    vertexArray.bind();

    const girafarig::graphics::buffer::VertexBuffer vertexBuffer;
    vertexBuffer.bind();
    girafarig::graphics::buffer::VertexBuffer::addVertices(vertices);

    const girafarig::graphics::buffer::IndexBuffer indexBuffer;
    indexBuffer.bind();
    girafarig::graphics::buffer::IndexBuffer::addIndices(indices);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(girafarig::Vertex), nullptr);
    glEnableVertexAttribArray(0);

    while (!window.shouldClose()) {
        window.processInput();

        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

        window.swapBuffers();
        glfwPollEvents();
    }

    girafarig::platform::GlfwContext::terminate();
    return 0;
}
