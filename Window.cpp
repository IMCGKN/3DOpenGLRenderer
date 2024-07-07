#include "Window.h"

void Window::framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void Window::Init(int w, int h, const std::string& t)
{
    width = w;
    height = h;
    title = t;
    if(!glfwInit())
        throw std::runtime_error("Failed to init GLFW!");
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
    if(window == nullptr)
    {
        throw std::runtime_error("Failed to create GLFWwindow: '" + title + "'!");
        glfwTerminate();
    }

    glfwMakeContextCurrent(window);

    glfwSetWindowSizeCallback(window, framebuffer_size_callback);
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);  

    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        throw std::runtime_error("Failed to load GLAD!");
        glfwDestroyWindow(window);
        glfwTerminate();
    }

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glFrontFace(GL_CW);

    glViewport(0, 0, width, height);
}

void Window::Update()
{
    glfwPollEvents();
    glfwSwapBuffers(window);

    if(isKeyPressed(GLFW_KEY_ESCAPE))
    {
        glfwSetWindowShouldClose(window, true);
    }

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}
