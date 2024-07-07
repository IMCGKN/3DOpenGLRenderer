#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <string>

class Window
{
private:
    GLFWwindow* window;
    int width, height;
    std::string title;

    float fov = 60.0f;
    float near = 0.01f;
    float far = 100.0f;

public:
    void Init(int w, int h, const std::string& t);

    void Update();

    static void framebuffer_size_callback(GLFWwindow* window, int width, int height);

    void getMousePos(double* x, double* y)
    {
        glfwGetCursorPos(window, x, y);
    }

    glm::mat4 getProjMatrix()
    {
        glm::mat4 proj = glm::mat4(1.0f);
        proj = glm::perspective(glm::radians(fov), (float)(width / height), near, far);
        return proj;
    }

    bool isOpen() const
    {
        return !glfwWindowShouldClose(window);
    }

    bool isKeyPressed(int key) const
    {
        return glfwGetKey(window, key) == GLFW_PRESS;
    }

    bool isMousePressed(int key) const
    {
        return glfwGetMouseButton(window, key) == GLFW_PRESS;
    }
};
