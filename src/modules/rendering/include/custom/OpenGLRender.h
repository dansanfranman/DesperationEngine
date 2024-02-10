#include <stdio.h>
#include <string>

#include "gl3w.h"
#include "glfw3.h"

#include "ServiceLocator.h"
#include "DEMath.h"

class OpenGLRender
{
        public:
                OpenGLRender();
                int Init(GLuint width, GLuint height, const char* title);
                int Render(double runtime);
                ~OpenGLRender();
        private:
                GLFWwindow* window;
};
