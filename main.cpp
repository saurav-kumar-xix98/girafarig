#include "glad/glad.h"
#include "graphics/Vertex.h"
#include "graphics/buffer/IndexBuffer.h"
#include "graphics/buffer/VertexArray.h"
#include "graphics/buffer/VertexBuffer.h"
#include "graphics/context/OpenGlContext.h"
#include "graphics/shader/ShaderProgram.h"
#include "math/Matrix.h"
#include "math/Quaternion.h"
#include "platform/GlfwContext.h"
#include "platform/Window.h"

int main() {
    girafarig::platform::GlfwContext::initialize();
    const girafarig::platform::Window window(800, 600, "Girafarig");
    girafarig::graphics::context::OpenGlContext::initialize();

    const girafarig::graphics::shader::ShaderProgram shaderProgram("./resource/shader/VertexShader.glsl", "./resource/shader/GeometryShader.glsl", "./resource/shader/FragmentShader.glsl");
    shaderProgram.useProgram();

    const std::vector<girafarig::Vertex> vertices = {
        { 0.0f,  0.0f, 0.0f }
    };

    const std::vector<unsigned int> indices = {
        0
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

    float angle = 0.0f;

    while (!window.shouldClose()) {
        window.processInput();

        shaderProgram.setUniform("uColor", {1.0f, 0.0f, 0.0f, 1.0f});
        auto projectionMatrix = girafarig::math::createPerspectiveProjectionMatrix(45.0f * 3.14f / 180.0f, window.aspectRatio(), 0.1f, 100.0f);
        shaderProgram.setUniform("uProjection", projectionMatrix);
        auto viewMatrix = girafarig::math::createViewMatrix({ 2.0f, 0.0f, 5.0f }, girafarig::math::Quaternion({0.0f, 0.0f, 1.0f}, angle * 3.14f / 180.0f));
        shaderProgram.setUniform("uView", viewMatrix);

        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glDrawElements(GL_POINTS, 1, GL_UNSIGNED_INT, nullptr);

        window.swapBuffers();
        glfwPollEvents();
        angle += 0.1f;
        while (angle > 360.0f) angle -= 360.0f;
    }

    girafarig::platform::GlfwContext::terminate();
    return 0;
}
