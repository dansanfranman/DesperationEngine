add_library(GLEW STATIC IMPORTED)
        set_target_properties(GLEW PROPERTIES IMPORTED_LOCATION "${CMAKE_CURRENT_SOURCE_DIR}/libs/glew32s.lib") 
add_library(GLFW STATIC IMPORTED)
        set_target_properties(GLFW PROPERTIES IMPORTED_LOCATION "${CMAKE_CURRENT_SOURCE_DIR}/libs/glfw3.lib")

        add_library(RENDERING
                        src/RenderingTest.cpp
                   )

        target_include_directories(RENDERING PUBLIC "include/custom")

        target_include_directories(GLEW INTERFACE "include/glew")
        target_include_directories(GLFW INTERFACE "include/glfw")

target_link_libraries(RENDERING PRIVATE GLEW GLFW)

