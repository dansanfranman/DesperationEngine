#include <iostream>
#include <string>

#include "ServiceLocator.h"
#include "WindowsLoggerProvider.h"
#include "OpenGLRender.h"

#include "Scene.h"
#include "GameObject.h"
#include "Model.h"
#include "GLMesh.h"
#include "GLShader.h"

#include "DesperationConfig.h"

void InitializeServices()
{
        ServiceLocator::SetLogger(new WindowsLoggerProvider());
}

int main()
{
        InitializeServices();
        OpenGLRender renderer;
        const char* title = "OpenGL Renderer";
        std::string msg = "Main init";
        DELOG("Main init");

        if(renderer.Init(1920, 1080, title) == -1)
        {
                std::string msg = "Renderer failed to init";
                DEERROR(msg.c_str(), __FILE__, __LINE__);
                return -1;
        }
        Scene scene;

        GLShader shader;
        shader.LoadShaderSourceFromFile(NULL);
        
        GameObject gameObject;
        GLMesh mesh;
        mesh.LoadFromFile(NULL);
        Model model {mesh};

        scene.RegisterModelWithGLShader(shader, model);

        while(renderer.Render(scene) > -1)
        {
                // we're cooking with gas baby
        }
        // std::string testMessage = "Hello World!" + " Your version number is: " + DesperationEngine_VERSION_MAJOR + "." + DesperationEngine_VERSION_MINOR;
        std::string testMessage = "Hello World!";
        DELOGF(testMessage.c_str(), __FILE__, __LINE__);
        return 0;
}
