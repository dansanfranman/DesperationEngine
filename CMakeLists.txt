message("Beginning CMake...")
cmake_minimum_required(VERSION 3.12)

project(DesperationEngine VERSION 0.1)
configure_file("${PROJECT_SOURCE_DIR}/include/DesperationConfig.h.in" "${PROJECT_SOURCE_DIR}/include/DesperationConfig.h")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MD /EHsc")

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SUBDIRS
        src/core
        src/modules
   )
foreach(DIR ${SUBDIRS})
        message("Adding subdirectory: ${DIR}")
        add_subdirectory(${DIR})
endforeach()

add_executable(${PROJECT_NAME} "src/main.cpp")
target_include_directories("${PROJECT_NAME}" PUBLIC 
                "include" 
                "src/core/logging/include" 
                "src/core/serviceprovider/include"
                "src/modules/rendering/include/custom")

target_link_libraries("${PROJECT_NAME}" PRIVATE Rendering ServiceProvider Logging)
