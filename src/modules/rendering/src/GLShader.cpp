#include "GLShader.h"

GLShader::GLShader()
{
        shaderProgram = 0;
        shaderIndex = 0;
}

void GLShader::CreateShader(const GLchar** source, GLenum shaderType)
{
        GLuint shaderID = glCreateShader(shaderType);
        glShaderSource(shaderID, 1, source, NULL);
        glCompileShader(shaderID);
        shaders[shaderIndex++] = shaderID;
}

void GLShader::CreateVertexShader(std::string vertexShaderSource)
{
        const char* c_str = vertexShaderSource.c_str();
        CreateShader(&c_str, GL_VERTEX_SHADER);
}

void GLShader::CreateFragmentShader(std::string fragmentShaderSource)
{
        const char* c_str = fragmentShaderSource.c_str();
        CreateShader(&c_str, GL_FRAGMENT_SHADER);
}

std::string GLShader::LoadShaderSourceFromFile(std::string filename)
{
        //TODO: correct implementation

        std::string vertexSource = 
                "#version 450 core                              \n" +
                std::string("void main(void)                                \n") +
                std::string("{                                              \n") +
                std::string("       gl_Position = vec4(0.0, 0.0, 0.5, 1.0); \n") +
                std::string("}                                              \n");
        std::string fragmentSource =
                "#version 450 core                              \n" +
                std::string("out vec4 color;                                \n") +
                std::string("void main(void)                                \n") +
                std::string("{                                              \n") +
                std::string("       color = vec4(0.0, 0.8, 1.0, 1.0);       \n") +
                std::string("}                                              \n");

        CreateVertexShader(vertexSource);
        CreateFragmentShader(fragmentSource);
        CreateProgram();
        //temp return value
        return vertexSource;
}

void GLShader::CreateProgram()
{
        shaderProgram = glCreateProgram();
        for(size_t i = 0; i < shaderIndex; i++)
        {
                glAttachShader(shaderProgram, shaders[i]);
        }

        glLinkProgram(shaderProgram);
}

void GLShader::CleanShadersArray()
{
        // once the program has been created we no longer need the shaders stored in memory
        // unless they are going to be used inside another shader program

        for(size_t i = 0; i < shaderIndex; i++)
        {
                glDeleteShader(shaders[i]);
        }

        shaderIndex = 0;
}

void GLShader::Use()
{
}

GLShader::~GLShader()
{
        CleanShadersArray();
        glDeleteProgram(shaderProgram);
        shaderProgram = 0;
        shaderIndex = 0;
}
