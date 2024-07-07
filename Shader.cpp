#include "Shader.h"

void Shader::Init(const char *vFileLoc, const char *fFileLoc)
{
    std::string sourceStringVert;
    std::string sourceStringFrag;

    std::ifstream vFile, fFile;

    vFile.exceptions(std::ios::badbit | std::ios::failbit);
    fFile.exceptions(std::ios::badbit | std::ios::failbit);

    try
    {
        vFile.open(vFileLoc);
        fFile.open(fFileLoc);

        std::stringstream ssVertex;
        std::stringstream ssFragment;

        ssVertex << vFile.rdbuf();
        ssFragment << fFile.rdbuf();

        sourceStringVert = ssVertex.str();
        sourceStringFrag = ssFragment.str();
    }
    catch(const std::exception& e)
    {
        std::cerr << "Failed to open vertex or fragment file!" << '\n';
    }

    const char* vertexSource = sourceStringVert.c_str();
    const char* fragmentSource = sourceStringFrag.c_str();

    unsigned int vertex, fragment;
    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vertexSource, nullptr);
    glCompileShader(vertex);
    CheckError(vertex, "Vertex");
    
    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fragmentSource, nullptr);
    glCompileShader(fragment);
    CheckError(fragment, "Fragment");

    ID = glCreateProgram();
    glAttachShader(ID, vertex);
    glAttachShader(ID, fragment);
    glLinkProgram(ID);

    glDeleteShader(vertex);
    glDeleteShader(fragment);
}

void Shader::CheckError(unsigned int shaderId, const char *type)
{
    int success;
    char infoLog[512];
    glGetShaderiv(shaderId, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(shaderId, 512, nullptr, infoLog);
        std::cout << type << ": " << infoLog << std::endl;
    }
    else
    {
        std::cout << "No errors in " << type << " shader!" << std::endl;
    }
}

void Shader::Use()
{
    if(!isCurrentlyUsed)
    {
        glUseProgram(ID);
        isCurrentlyUsed = true;
    }
}

void Shader::Unuse()
{
    if(isCurrentlyUsed)
    {
        glUseProgram(0);
        isCurrentlyUsed = false;
    }
}

void Shader::Delete()
{
    glDeleteProgram(ID);
}

void Shader::SetMat4(const std::string &name, glm::mat4 &mat)
{
    Use();
    glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, glm::value_ptr(mat));
}

void Shader::SetVec3(const std::string &name, glm::vec3 &vec)
{
    Use();
    glUniform3fv(glGetUniformLocation(ID, name.c_str()), 1, glm::value_ptr(vec));
}

void Shader::SetFloat(const std::string &name, float val)
{
    Use();
    glUniform1f(glGetUniformLocation(ID, name.c_str()), val);
}

void Shader::SetInt(const std::string &name, int val)
{
    Use();
    glUniform1i(glGetUniformLocation(ID, name.c_str()), val);
}
