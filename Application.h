#pragma once

#include <vector>

#include "Window.h"
#include "Camera.h"
#include "Shader.h"
#include "GameObject.h"

#define TWO_PI 6.28318530717958647693

class App
{
private:
    float dt = 0.0f;
    bool canShoot = true;
    float cooldown = 0.0f;
    Window mainWindow;
    Shader mainShader;
    Camera camera;

    GameObject planeObj;
    GameObject cubeObj;
    std::vector<GameObject> rayObjects;

    glm::vec3 sunPos = glm::vec3(0.71f, 0.8f, 1.0f);
    glm::vec3 sunCol = glm::vec3(1.0f, 1.0f, 1.0f);

    std::vector<float> rayVerts = {
        0.0f, 0.0f, 0.0f,    1.0f, 0.0f, 0.0f,    0.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 0.0f,    0.0f, 1.0f, 0.0f,    0.0f, 0.0f, 0.0f,
    };

public:
    void Init();

private:
    void Loop();
};
