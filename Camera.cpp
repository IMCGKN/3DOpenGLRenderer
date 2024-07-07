#include "Camera.h"

void Camera::Update(Window &window, float dt)
{
    window.getMousePos(&mouseX, &mouseY);
    if(window.isKeyPressed(GLFW_KEY_W))
    {
        cameraPos += cameraFront * moveSpeed * dt;
    }
    if(window.isKeyPressed(GLFW_KEY_S))
    {
        cameraPos -= cameraFront * moveSpeed * dt;
    }
    if(window.isKeyPressed(GLFW_KEY_A))
    {
        cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * moveSpeed * dt;
    }
    if(window.isKeyPressed(GLFW_KEY_D))
    {
        cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * moveSpeed * dt;
    }

    if (firstMouse)
    {
        lastX = mouseX;
        lastY = mouseY;
        firstMouse = false;
    }
  
    float xoffset = mouseX - lastX;
    float yoffset = lastY - mouseY; 
    lastX = mouseX;
    lastY = mouseY;

    xoffset *= sensitivity;
    yoffset *= sensitivity;

    yaw   += xoffset * dt;
    pitch += yoffset * dt;

    if(pitch > 89.0f)
        pitch = 89.0f;
    if(pitch < -89.0f)
        pitch = -89.0f;

    glm::vec3 direction;
    direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    direction.y = sin(glm::radians(pitch));
    direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    cameraFront = glm::normalize(direction);
}

void Camera::SetMatrices(Window &window, Shader &shader)
{
    shader.Use();
    glm::mat4 proj = window.getProjMatrix();
    shader.SetMat4("Projection", proj);
    glm::mat4 view = glm::mat4(1.0f);
    view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
    shader.SetMat4("View", view);
    shader.Unuse();
}
