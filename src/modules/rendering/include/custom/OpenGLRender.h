#include <stdio.h>
#include <string>

#include "GL/gl3w.h"
#include "glfw3.h"

#include "ServiceLocator.h"
#include "DEMath.h"
#include "GLShader.h"

#include "Scene.h"
#include "Model.h"
#include "GLMesh.h"
#include "GLMaterial.h"

class OpenGLRender
{
        public:
                OpenGLRender();
                int Init(GLuint width, GLuint height, const char* title);
                int Render(Scene& scene);
                void PrepareModelForRendering(Model& model);
                void SetMaterial(GLMaterial& material);
                void DrawMesh(GLMesh& mesh);
                ~OpenGLRender();
        private:
                GLFWwindow* window;
};
