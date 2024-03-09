#pragma once

#include <vector>
#include "GLMesh.h"
class Model
{
        public:
                Model(const GLMesh& mesh);
                const std::vector<GLMesh>& GetMeshes();
                void SetReadyToRender();
                bool IsReadyToRender();

        private:
                bool isReadyToRender;
                std::vector<GLMesh> meshes; //for now, meshes cannot be changed after construction. Pass data to constructor
};
