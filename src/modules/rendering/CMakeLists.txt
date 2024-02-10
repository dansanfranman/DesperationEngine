add_library(GLFW STATIC IMPORTED)
set_target_properties(GLFW PROPERTIES IMPORTED_LOCATION "${CMAKE_CURRENT_SOURCE_DIR}/libs/glfw3.lib")
target_include_directories(GLFW INTERFACE "include/glfw")

add_library(GL3W 
                libs/gl3w.c
           )
target_include_directories(GL3W PRIVATE "include/gl3w")

add_library(Rendering
                src/OpenGLRender.cpp
           )

target_include_directories(Rendering PUBLIC "include/custom" 
                                            "include/glfw"
                                            "include/gl3w"
                                            "${CMAKE_CURRENT_SOURCE_DIR}/../../core/serviceprovider/include"
                                            "${CMAKE_CURRENT_SOURCE_DIR}/../../core/logging/include"
                                            "${CMAKE_CURRENT_SOURCE_DIR}/../../core/demath/include"
                                            )


target_link_libraries(Rendering PRIVATE opengl32 GL3W GLFW ServiceProvider DEMath) 
