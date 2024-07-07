#pragma once

#include <glad/glad.h>

#include "VertexBufferObject.h"

class VertexArrayObject
{
private:
    unsigned int ID;

    bool isUsing = false;
public:
    void Init()
    {
        glGenVertexArrays(1, &ID);
        Use();
    }

    void LinkAttrib(VertexBufferObject& VBO, unsigned int index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer)
    {
        Use();
        VBO.Use();
        glVertexAttribPointer(index, size, type, normalized, stride, pointer);
        glEnableVertexAttribArray(index);
        VBO.Unuse();
        Unuse();
    }

    void Use()
    {
        if(!isUsing)
        {
            isUsing = true;
            glBindVertexArray(ID);
        }
    }

    void Unuse()
    {
        if(isUsing)
        {
            isUsing = false;
            glBindVertexArray(0);
        }
    }

    void Delete()
    {
        glDeleteVertexArrays(1, &ID);
    }
};
