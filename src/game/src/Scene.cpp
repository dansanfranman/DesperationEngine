#include "Scene.h"

Scene::Scene()
{
}

std::unordered_map<std::string, std::string> Scene::GetRenderData()
{
        return renderData;
}

void Scene::RegisterModelWithGLShader(GLShader& shader, Model& model)
{
//        if(!renderData.count(shader))
//        {
//                renderData[shader] = std::vector<Model>();
//        }
//        renderData[shader].push_back(model);
}

Scene::~Scene()
{
}
