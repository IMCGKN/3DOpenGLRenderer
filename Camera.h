#pragma once

#include "Shader.h"
#include "Window.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Camera
{
private:
    glm::vec3 cameraPos =   glm::vec3(0.0f, 0.0f,-3.0f);
    glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f,-1.0f);
    glm::vec3 cameraUp =    glm::vec3(0.0f, 1.0f, 0.0f);

    float moveSpeed = 5.0f;
    float sensitivity = 95.0f;
    double mouseX = 0.0, mouseY = 0.0;
    bool firstMouse = true;
    float yaw = -90.0f, pitch = 0.0f;
    float lastX = 400.0f, lastY = 300.0f;
public:
    void Update(Window &window, float dt);

    void SetMatrices(Window& window, Shader &shader);

    glm::vec3 getPos() const
    {
        return cameraPos;
    }

    glm::vec3 getCameraFront() const
    {
        return cameraFront;
    }
};
