#pragma once

#include <glad/glad.h>

#include <vector>

class VertexBufferObject
{
private:
    unsigned int ID;
public:
    void Init(std::vector<float>& vertices)
    {
        glGenBuffers(1, &ID);
        Use();
        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);
        Unuse();
    }

    void Update(std::vector<float>& vertices)
    {
        Use();
        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);
        Unuse();
    }

    void Use()
    {
        glBindBuffer(GL_ARRAY_BUFFER, ID);
    }

    void Unuse()
    {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    void Delete()
    {
        glDeleteBuffers(1, &ID);
    }
};