#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <glad/glad.h>

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

class Shader
{
private:
    unsigned int ID;

    bool isCurrentlyUsed = false;

public:
    void Init(const char* vFileLoc, const char* fFileLoc);

    void CheckError(unsigned int shaderId, const char* type);

    void Use();
    void Unuse();
    void Delete();

    void SetMat4(const std::string& name, glm::mat4& mat);
    void SetVec3(const std::string& name, glm::vec3& vec);
    void SetFloat(const std::string& name, float val);
    void SetInt(const std::string& name, int val);
};
