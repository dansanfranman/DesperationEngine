add_library(GLFW STATIC IMPORTED)
set_target_properties(GLFW PROPERTIES IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/libs/glfw3.lib)
target_include_directories(GLFW INTERFACE include/glfw)

add_library(Rendering
                libs/gl3w.c
                src/OpenGLRender.cpp
                src/GLShader.cpp
           )

target_include_directories(Rendering PUBLIC include/gl3w include/custom) 
target_link_libraries(Rendering PUBLIC GLFW PRIVATE opengl32 ServiceProvider DEMath Logging Game) 
