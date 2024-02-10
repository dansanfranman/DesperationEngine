#include "OpenGLRender.h"


OpenGLRender::OpenGLRender()
{
    window = nullptr;
}

int OpenGLRender::Init(GLuint width, GLuint height, const char* title)
{
        if(!glfwInit())
        {
                std::string msg = "glfwInit failed";
                ServiceLocator::GetLogger()->Error(msg.c_str(), __FILE__, __LINE__);
                return -1;
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        window = glfwCreateWindow(width, height, title, NULL, NULL);

        if(!window)
        {
                std::string msg = "window failed";
                ServiceLocator::GetLogger()->Error(msg.c_str(), __FILE__, __LINE__);
                glfwTerminate();
                return -1;
        }

        glfwMakeContextCurrent(window);

        if(gl3wInit() != 0)
        {
                std::string msg = "Failed to init gl3w";
                ServiceLocator::GetLogger()->Error(msg.c_str(), __FILE__, __LINE__);
                glfwTerminate();
                return -1;
        }

        if(!gl3wIsSupported(4,5))
        {
                std::string msg = "OpenGL Version 4.5 is not supported";
                ServiceLocator::GetLogger()->Error(msg.c_str(), __FILE__, __LINE__);
                glfwTerminate();
                return -1;
        }

        return 0;
}

int OpenGLRender::Render()
{
        static const GLfloat red[] = { 1.0f, 0.0f, 0.0f, 1.0f };
        if(!glfwWindowShouldClose(window))
        {
                glClearBufferfv(GL_COLOR, 0, red); //-- this line is causing issues, evidently i'm not using it correctly
                glfwSwapBuffers(window);

                glfwPollEvents();
                return 0;
        }
        std::string msg = "window closed";
        ServiceLocator::GetLogger()->Log(msg.c_str(), __FILE__, __LINE__);
        return -1;
}

OpenGLRender::~OpenGLRender()
{
        if(window)
        {
                glfwDestroyWindow(window);
        }

        glfwTerminate();
}
