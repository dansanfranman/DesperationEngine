#include "Model.h"

Model::Model(const GLMesh& mesh)
{
        meshes.push_back(mesh);
}

const std::vector<GLMesh>& Model::GetMeshes()
{
        return meshes;
}

void Model::SetReadyToRender()
{
        isReadyToRender = true;
}

bool Model::IsReadyToRender()
{
        return isReadyToRender;
}
