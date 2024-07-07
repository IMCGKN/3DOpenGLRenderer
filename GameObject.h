#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <vector>

#include "VertexArrayObject.h"
#include "VertexBufferObject.h"
#include "Shader.h"

class GameObject
{
private:
    VertexArrayObject VAO;
    VertexBufferObject VBO;

    glm::vec3 position;
    glm::vec3 scale;

public:
    void Init(std::vector<float>& verts, glm::vec3 pos, glm::vec3 scale);

    void Draw(Shader& shader);

    void UpdateVAOVBO();

    bool isRay = false;
    std::vector<float> vertices;
};
