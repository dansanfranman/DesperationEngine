#include <iostream>
#include <string>

#include "ServiceLocator.h"
#include "OpenGLRender.h"
#include "WindowsLoggerProvider.h"

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
        ServiceLocator::GetLogger()->Log(msg.c_str());

        if(renderer.Init(1920, 1080, title) == -1)
        {
                ServiceLocator::GetLogger()->Error("Renderer failed to init", __FILE__, __LINE__);
                return -1;
        }

        while(renderer.Render() > -1)
        {
                // we're cooking with gas baby
        }
        // std::string testMessage = "Hello World!" + " Your version number is: " + DesperationEngine_VERSION_MAJOR + "." + DesperationEngine_VERSION_MINOR;
        std::string testMessage = "Hello World!";
        ServiceLocator::GetLogger()->Log(testMessage.c_str(), __FILE__, __LINE__);
        return 0;
}
