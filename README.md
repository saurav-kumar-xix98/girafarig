# Girafarig - A minimal OpenGL rendering engine
![Girafarig](https://www.pokemon.com/static-assets/content-assets/cms2/img/pokedex/full/203.png)

Currently renders a rectangle using:
- Vertex buffers
- Index buffers
- Vertex arrays
- GLSL shaders
- OpenGL 3.3 Core

## Dependencies

- CMake >= 3.10
- OpenGL
- GLFW3

GLAD is included as a local dependency.

## Build

```bash
mkdir build
cd build

cmake ..
make
```

## Run

From the `build` directory:

```bash
./girafarig
```

## Project Structure

```text
include/
    graphics/
        buffer/
        context/
        shader/
    platform/

src/
    graphics/
    platform/

resource/
    shader/
```

## Features

- GLFW window abstraction
- OpenGL context initialization
- Shader compilation and linking
- Vertex buffer abstraction
- Index buffer abstraction
- Vertex array abstraction

## Rendering Pipeline

The application:
1. Initializes GLFW
2. Creates a window
3. Loads OpenGL with GLAD
4. Compiles shaders
5. Uploads vertex/index data
6. Draws indexed geometry using `glDrawElements`

## Shaders

Vertex shader:
- Accepts vertex positions

Fragment shader:
- Outputs a solid red color

## Example Output

A red rectangle rendered on a black background.
