add_library(GLEW STATIC IMPORTED)
set_target_properties(GLEW PROPERTIES IMPORTED_LOCATION "${CMAKE_CURRENT_SOURCE_DIR}/libs/glew32s.lib") 

add_library(GLFW STATIC IMPORTED)
set_target_properties(GLFW PROPERTIES IMPORTED_LOCATION "${CMAKE_CURRENT_SOURCE_DIR}/libs/glfw3.lib")

add_library(GL3W 
                libs/gl3w.c
           )
target_include_directories(GL3W PRIVATE "include/gl3w")

add_library(Rendering
                src/OpenGLRender.cpp
           )
message("logging dir: ${CMAKE_CURRENT_SOURCE_DIR}/../../core/logging/include")
target_include_directories(Rendering PUBLIC "include/custom" 
                                            "include/glew" 
                                            "include/glfw"
                                            "include/gl3w"
                                            "${CMAKE_CURRENT_SOURCE_DIR}/../../core/serviceprovider/include"
                                            "${CMAKE_CURRENT_SOURCE_DIR}/../../core/logging/include"
                                            )

target_include_directories(GLEW INTERFACE "include/glew")
target_include_directories(GLFW INTERFACE "include/glfw")

target_link_libraries(Rendering PRIVATE opengl32 GL3W GLEW GLFW ServiceProvider)
