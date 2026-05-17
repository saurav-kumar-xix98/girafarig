cmake_minimum_required(VERSION 3.10)

project(Girafarig)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

# -------------------------
# GLAD
# -------------------------
add_library(glad dependencies/glad/src/glad.c)

target_include_directories(glad PUBLIC
    dependencies/glad/include
)

# -------------------------
# Main executable
# -------------------------
add_executable(girafarig
    main.cpp
    src/Window.cpp
        src/GlfwContext.cpp
        include/OpenGlContext.h
        src/OpenGlContext.cpp
        src/Shader.cpp
        src/ShaderProgram.cpp
)

target_include_directories(girafarig PRIVATE
    include
)

target_link_libraries(girafarig
    PRIVATE
    glad
    glfw
    OpenGL::GL
    dl
)

# -------------------------
# Copy resources
# -------------------------
file(COPY resource
    DESTINATION ${CMAKE_BINARY_DIR}
)
