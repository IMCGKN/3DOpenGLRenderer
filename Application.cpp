#include "Application.h"

void App::Init()
{
    mainWindow.Init(1280, 920, "OpenGL 3D Renderer");
    mainShader.Init("res\\shaders\\vertex.glsl", "res\\shaders\\fragment.glsl");

    std::vector<float> planeVerts = {
        -0.5f, 0.0f, 0.5f,  0.35f, 0.35f, 0.35f,  -1.0f, -1.0f,-1.0f,
         0.5f, 0.0f,-0.5f,  0.35f, 0.35f, 0.35f,  -1.0f, -1.0f,-1.0f,
         0.5f, 0.0f, 0.5f,  0.35f, 0.35f, 0.35f,  -1.0f, -1.0f,-1.0f,

        -0.5f, 0.0f, 0.5f,  0.35f, 0.35f, 0.35f,  -1.0f, -1.0f,-1.0f,
        -0.5f, 0.0f,-0.5f,  0.35f, 0.35f, 0.35f,  -1.0f, -1.0f,-1.0f,
         0.5f, 0.0f,-0.5f,  0.35f, 0.35f, 0.35f,  -1.0f, -1.0f,-1.0f,
    };

    std::vector<float> cubeVerts = {
        // Back face
        -0.5f, -0.5f, -0.5f,  0.75f, 0.75f, 0.75f,  0.0f, 0.0f, -1.0f, // Bottom-left
         0.5f, -0.5f, -0.5f,  0.75f, 0.75f, 0.75f,  0.0f, 0.0f, -1.0f, // bottom-right    
         0.5f,  0.5f, -0.5f,  0.75f, 0.75f, 0.75f,  0.0f, 0.0f, -1.0f, // top-right              
         0.5f,  0.5f, -0.5f,  0.75f, 0.75f, 0.75f,  0.0f, 0.0f, -1.0f, // top-right
        -0.5f,  0.5f, -0.5f,  0.75f, 0.75f, 0.75f,  0.0f, 0.0f, -1.0f, // top-left
        -0.5f, -0.5f, -0.5f,  0.75f, 0.75f, 0.75f,  0.0f, 0.0f, -1.0f, // bottom-left
        // Front face
        -0.5f, -0.5f,  0.5f,  0.75f, 0.75f, 0.75f,  0.0f, 0.0f,  1.0f, // bottom-left
         0.5f,  0.5f,  0.5f,  0.75f, 0.75f, 0.75f,  0.0f, 0.0f,  1.0f, // top-right
         0.5f, -0.5f,  0.5f,  0.75f, 0.75f, 0.75f,  0.0f, 0.0f,  1.0f, // bottom-right        
         0.5f,  0.5f,  0.5f,  0.75f, 0.75f, 0.75f,  0.0f, 0.0f,  1.0f, // top-right
        -0.5f, -0.5f,  0.5f,  0.75f, 0.75f, 0.75f,  0.0f, 0.0f,  1.0f, // bottom-left
        -0.5f,  0.5f,  0.5f,  0.75f, 0.75f, 0.75f,  0.0f, 0.0f,  1.0f, // top-left        
        // Left face
        -0.5f,  0.5f,  0.5f,  0.75f, 0.75f, 0.75f,  -1.0f, 0.0f, 0.0f, // top-right
        -0.5f, -0.5f, -0.5f,  0.75f, 0.75f, 0.75f,  -1.0f, 0.0f, 0.0f, // bottom-left
        -0.5f,  0.5f, -0.5f,  0.75f, 0.75f, 0.75f,  -1.0f, 0.0f, 0.0f, // top-left       
        -0.5f, -0.5f, -0.5f,  0.75f, 0.75f, 0.75f,  -1.0f, 0.0f, 0.0f, // bottom-left
        -0.5f,  0.5f,  0.5f,  0.75f, 0.75f, 0.75f,  -1.0f, 0.0f, 0.0f, // top-right
        -0.5f, -0.5f,  0.5f,  0.75f, 0.75f, 0.75f,  -1.0f, 0.0f, 0.0f, // bottom-right
        // Right face
         0.5f,  0.5f,  0.5f,  0.75f, 0.75f, 0.75f,   1.0f, 0.0f, 0.0f, // top-left
         0.5f,  0.5f, -0.5f,  0.75f, 0.75f, 0.75f,   1.0f, 0.0f, 0.0f, // top-right      
         0.5f, -0.5f, -0.5f,  0.75f, 0.75f, 0.75f,   1.0f, 0.0f, 0.0f, // bottom-right 
         0.5f, -0.5f, -0.5f,  0.75f, 0.75f, 0.75f,   1.0f, 0.0f, 0.0f, // bottom-right
         0.5f, -0.5f,  0.5f,  0.75f, 0.75f, 0.75f,   1.0f, 0.0f, 0.0f, // bottom-left
         0.5f,  0.5f,  0.5f,  0.75f, 0.75f, 0.75f,   1.0f, 0.0f, 0.0f, // top-left
        // Bottom face          
        -0.5f, -0.5f, -0.5f,  0.75f, 0.75f, 0.75f,  0.0f,  1.0f, 0.0f, // top-right
         0.5f, -0.5f,  0.5f,  0.75f, 0.75f, 0.75f,  0.0f,  1.0f, 0.0f, // bottom-left
         0.5f, -0.5f, -0.5f,  0.75f, 0.75f, 0.75f,  0.0f,  1.0f, 0.0f, // top-left        
         0.5f, -0.5f,  0.5f,  0.75f, 0.75f, 0.75f,  0.0f,  1.0f, 0.0f, // bottom-left
        -0.5f, -0.5f, -0.5f,  0.75f, 0.75f, 0.75f,  0.0f,  1.0f, 0.0f, // top-right
        -0.5f, -0.5f,  0.5f,  0.75f, 0.75f, 0.75f,  0.0f,  1.0f, 0.0f, // bottom-right
        // Top face
        -0.5f,  0.5f, -0.5f,  0.75f, 0.75f, 0.75f,  0.0f, -1.0f, 0.0f, // top-left
         0.5f,  0.5f, -0.5f,  0.75f, 0.75f, 0.75f,  0.0f, -1.0f, 0.0f, // top-right
         0.5f,  0.5f,  0.5f,  0.75f, 0.75f, 0.75f,  0.0f, -1.0f, 0.0f, // bottom-right
         0.5f,  0.5f,  0.5f,  0.75f, 0.75f, 0.75f,  0.0f, -1.0f, 0.0f, // bottom-right
        -0.5f,  0.5f,  0.5f,  0.75f, 0.75f, 0.75f,  0.0f, -1.0f, 0.0f, // bottom-left  
        -0.5f,  0.5f, -0.5f,  0.75f, 0.75f, 0.75f,  0.0f, -1.0f, 0.0f, // top-left              
    };

    planeObj.Init(planeVerts, glm::vec3(0.0f, -4.0f, 0.0f), glm::vec3(20.0f, 1.0f, 20.0f));
    cubeObj.Init(cubeVerts, glm::vec3(-2.0f, 2.0f, -2.0f), glm::vec3(1.0f, 1.0f, 1.0f));

    mainShader.SetVec3("sunPos", sunPos);
    mainShader.SetVec3("sunCol", sunCol);

    Loop();
}

void App::Loop()
{
    float lastFrame = (float)glfwGetTime();
    while(mainWindow.isOpen())
    {
        float newFrame = glfwGetTime();
        dt = newFrame - lastFrame;
        lastFrame = newFrame;

        mainWindow.Update();
        camera.Update(mainWindow, dt);

        planeObj.Draw(mainShader);
        cubeObj.Draw(mainShader);
        for(auto& ray : rayObjects)
            ray.Draw(mainShader);

        camera.SetMatrices(mainWindow, mainShader);

        if(canShoot == true)
        {
            if(mainWindow.isMousePressed(GLFW_MOUSE_BUTTON_LEFT))
            {
                canShoot = false;
                GameObject newRay;
                newRay.Init(rayVerts, glm::vec3(), glm::vec3(1.0f, 1.0f, 1.0f));
                newRay.isRay = true;
                
                newRay.vertices.at(0) = camera.getPos().x + 0.6f;
                newRay.vertices.at(1) = camera.getPos().y - 0.3f;
                newRay.vertices.at(2) = camera.getPos().z;
                newRay.vertices.at(3) = 1.0f;
                newRay.vertices.at(4) = 0.0f;
                newRay.vertices.at(5) = 0.0f;
                newRay.vertices.at(6) = 0.0f;
                newRay.vertices.at(7) = 0.0f;
                newRay.vertices.at(8) = 0.0f;
                newRay.vertices.at(9) = camera.getPos().x + camera.getCameraFront().x * 1000;
                newRay.vertices.at(10) = camera.getPos().y + camera.getCameraFront().y * 1000;
                newRay.vertices.at(11) = camera.getPos().z + camera.getCameraFront().z * 1000;
                newRay.vertices.at(12) = 1.0f;
                newRay.vertices.at(13) = 0.0f;
                newRay.vertices.at(14) = 0.0f;
                newRay.vertices.at(15) = 0.0f;
                newRay.vertices.at(16) = 0.0f;
                newRay.vertices.at(17) = 0.0f;
                newRay.UpdateVAOVBO();

                rayObjects.push_back(newRay);
            }
        }
        else
        {
            cooldown += dt;
            if(cooldown >= 0.2f)
            {
                canShoot = true;
                cooldown = 0.0f;
            }
        }

    }
}
