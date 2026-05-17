#include <vector>

#include "GlfwContext.h"
#include "IndexBuffer.h"
#include "OpenGlContext.h"
#include "ShaderProgram.h"
#include "Vertex.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "Window.h"

#include <glad/glad.h>

int main() {
    girafarig::GlfwContext::initialize();
    const girafarig::Window window(800, 600, "Girafagir");
    girafarig::OpenGlContext::initialize();

    const girafarig::ShaderProgram shaderProgram("./resource/shader/VertexShader.glsl", "./resource/shader/FragmentShader.glsl");
    shaderProgram.useProgram();

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

    const girafarig::VertexArray vertexArray;
    vertexArray.bind();

    const girafarig::VertexBuffer vertexBuffer;
    vertexBuffer.bind();
    girafarig::VertexBuffer::addVertices(vertices);

    const girafarig::IndexBuffer indexBuffer;
    indexBuffer.bind();
    girafarig::IndexBuffer::addIndices(indices);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(girafarig::Vertex), (void*)0);
    glEnableVertexAttribArray(0);

    while (!window.shouldClose()) {
        window.processInput();

        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        window.swapBuffers();
        glfwPollEvents();
    }

    girafarig::GlfwContext::terminate();
    return 0;
}
