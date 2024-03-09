#pragma once

#include <vector>
#include <unordered_map>
#include <memory>

#include "GLShader.h"
#include "Model.h"

class Scene
{
        public:
                Scene();
                std::unordered_map<std::string, std::string> GetRenderData();
                void RegisterModelWithGLShader(GLShader& shader, Model& model);
                ~Scene();
        private:
                std::unordered_map<std::string, std::string> renderData;
};
