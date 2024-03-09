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
                DEERROR(msg.c_str(), __FILE__, __LINE__);
                return -1;
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        window = glfwCreateWindow(width, height, title, NULL, NULL);

        if(!window)
        {
                std::string msg = "window failed";
                DEERROR(msg.c_str(), __FILE__, __LINE__);
                glfwTerminate();
                return -1;
        }

        glfwMakeContextCurrent(window);

        if(gl3wInit() != 0)
        {
                std::string msg = "Failed to init gl3w";
                DELOGF(msg.c_str(), __FILE__, __LINE__);
                glfwTerminate();
                return -1;
        }

        if(!gl3wIsSupported(4,5))
        {
                std::string msg = "OpenGL Version 4.5 is not supported";
                DELOGF(msg.c_str(), __FILE__, __LINE__);
                glfwTerminate();
                return -1;
        }

        return 0;
}

int OpenGLRender::Render(Scene& scene)
{
        const GLfloat color[] {1.0f, 0.0f, 0.0f, 1.0f};
        if(!glfwWindowShouldClose(window))
        {
                glClearBufferfv(GL_COLOR, 0, color);
                glfwSwapBuffers(window);
                for (const auto& [shader, models] : scene.GetRenderData())
                {
//                        shader->Use();
//                        for (const Model& model : models)
//                        {
//                                if (!model.IsReadyToRender())
//                                {
//                                        PrepareModelForRendering(model);
//                                }
//                                SetMaterial(model.GetMaterial());
//                                DrawMesh(model.GetMesh());
//                        }
                }


                // TODO: glfwPollEvents will get user input which we will want to do at regular intervals
                // Render is not going to be called at regular intervals, and so this is not a suitable place for
                // this code to sit. It should be moved to within the fixed time processing step of the game loop
                // when the game loop is available
                glfwPollEvents();
                return 0;
        }
        std::string msg = "window closed";
        DELOGF(msg.c_str(), __FILE__, __LINE__);
        return -1;
}

void OpenGLRender::PrepareModelForRendering(Model& model)
{
        model.SetReadyToRender();
}

void OpenGLRender::SetMaterial(GLMaterial& material)
{
}

void OpenGLRender::DrawMesh(GLMesh& mesh)
{
}

OpenGLRender::~OpenGLRender()
{
        if(window)
        {
                glfwDestroyWindow(window);
        }

        glfwTerminate();
}
