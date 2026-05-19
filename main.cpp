#include <cmath>
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

#include "math/matrix.h"

girafarig::math::Matrix<4, 4> perspective(const float fovYRadians, const float aspectRatio, const float near, const float far) {
    const float k = std::tan(fovYRadians * 0.5f);
    return {
        { 1 / (k * aspectRatio), 0.0f, 0.0f, 0.0f },
        { 0.0f, 1 / k, 0.0f, 0.0f },
        { 0.0f, 0.0f, (far + near) / (near - far), 2 * far * near / (near - far) },
        { 0.0f, 0.0f, -1.0f, 0.0f }
    };
}

int main() {
    girafarig::platform::GlfwContext::initialize();
    const girafarig::platform::Window window(800, 600, "Girafarig");
    girafarig::graphics::context::OpenGlContext::initialize();

    const girafarig::graphics::shader::ShaderProgram shaderProgram("./resource/shader/VertexShader.glsl", "./resource/shader/FragmentShader.glsl");
    shaderProgram.useProgram();

    const std::vector<girafarig::Vertex> vertices = {
        { 0.5f,  0.5f, -1.0f},
        { 0.5f, -0.5f, -1.0f},
        {-0.5f, -0.5f, -1.0f},
        {-0.5f,  0.5f, -1.0f}
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

        shaderProgram.setUniform("uColor", {1.0f, 0.0f, 0.0f, 1.0f});
        shaderProgram.setUniform("uPerspective", perspective(45.0f * 3.14 / 180.0f, window.aspectRatio(), 0.1f, 100.0f));

        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

        window.swapBuffers();
        glfwPollEvents();
    }

    girafarig::platform::GlfwContext::terminate();
    return 0;
}
