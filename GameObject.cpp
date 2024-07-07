#include "GameObject.h"

void GameObject::Init(std::vector<float> &verts, glm::vec3 pos, glm::vec3 scale)
{
    vertices = verts;
    VAO.Init();
    VAO.Use();
    VBO.Init(vertices);
    VBO.Use();
    VAO.LinkAttrib(VBO, 0, 3, GL_FLOAT, GL_FALSE, (9 * sizeof(float)), (void*)0);
    VAO.LinkAttrib(VBO, 1, 3, GL_FLOAT, GL_FALSE, (9 * sizeof(float)), (void*)(3 * sizeof(float)));
    VAO.LinkAttrib(VBO, 2, 3, GL_FLOAT, GL_FALSE, (9 * sizeof(float)), (void*)(6 * sizeof(float)));
    VBO.Unuse();
    VAO.Unuse();

    this->position = pos;
    this->scale = scale;
}

void GameObject::Draw(Shader &shader)
{
    shader.Use();

    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, position);
    model = glm::scale(model, scale);
    shader.SetMat4("Model", model);
    
    VAO.Use();
    if(isRay)
    {
        glLineWidth(1);
        glDrawArrays(GL_LINES, 0, vertices.size() / 6);
    }
    else if(!isRay)
    {
        glLineWidth(6);
        glDrawArrays(GL_TRIANGLES, 0, vertices.size() / 6);
    }

    VAO.Unuse();
    shader.Unuse();
}

void GameObject::UpdateVAOVBO()
{
    VAO.Use();
    VBO.Use();
    VBO.Update(vertices);
    VAO.LinkAttrib(VBO, 0, 3, GL_FLOAT, GL_FALSE, (9 * sizeof(float)), (void*)0);
    VAO.LinkAttrib(VBO, 1, 3, GL_FLOAT, GL_FALSE, (9 * sizeof(float)), (void*)(3 * sizeof(float)));
    VAO.LinkAttrib(VBO, 2, 3, GL_FLOAT, GL_FALSE, (9 * sizeof(float)), (void*)(6 * sizeof(float)));
    VBO.Unuse();
    VAO.Unuse();
}
