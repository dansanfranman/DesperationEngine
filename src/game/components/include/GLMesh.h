#pragma once
#include <vector>
#include <string>
#include "demath.h"

class GLMesh
{
        public:
                GLMesh();
                void LoadFromFile(const std::string filename);
                ~GLMesh();
        private:
                std::vector<dem::Vec3> vertices;
                std::vector<size_t> indices;
};
