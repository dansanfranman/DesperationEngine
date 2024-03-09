message("Adding game library")

add_library(Game
                components/src/GameObject.cpp
                src/Scene.cpp
           )

target_include_directories(Game PUBLIC 
                                include
                                )

add_subdirectory(components)
target_link_libraries(Game PUBLIC GameComponent PRIVATE DEMath Rendering)
