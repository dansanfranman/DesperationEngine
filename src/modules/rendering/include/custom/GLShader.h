#pragma once

#include <string>
#include <memory>
#include <vector>

#include "GL/gl3w.h"
#include "Model.h"

class GLShader
{
        public:
                GLShader();
                void CreateVertexShader(std::string vertexShaderSource);
                void CreateFragmentShader(std::string fragmentShaderSource);
                void CreateProgram();
                std::string LoadShaderSourceFromFile(std::string filename);
                void CleanShadersArray();
                void Use();

                ~GLShader();

        private:
                void CreateShader(const GLchar** source, GLenum shaderType);
                int shaderIndex;
                GLuint shaders[2];
                GLuint shaderProgram;
};
