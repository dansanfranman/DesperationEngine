message("adding library: GameComponent")

add_library(GameComponent
                src/Model.cpp
                src/GLMesh.cpp
                src/GLMaterial.cpp
           )

target_include_directories(GameComponent PUBLIC include)

target_link_libraries(GameComponent PRIVATE DEMath)
