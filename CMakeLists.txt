message("Beginning CMake...")
cmake_minimum_required(VERSION 3.12)

project(DesperationEngine VERSION 0.1)
message("Debug compile flag set")
add_compile_definitions(DEBUG)
configure_file(${PROJECT_SOURCE_DIR}/include/DesperationConfig.h.in ${PROJECT_SOURCE_DIR}/include/DesperationConfig.h)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MD /EHsc")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

message("C++ 17 standard set")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SUBDIRS
        src/core
        src/modules
        src/game
   )
foreach(DIR ${SUBDIRS})
        message("Adding subdirectory: ${DIR}")
        add_subdirectory(${DIR})
endforeach()

message("adding ${PROJECT_NAME}.exe")
add_executable(${PROJECT_NAME} src/main.cpp)
target_include_directories("${PROJECT_NAME}" PRIVATE include)

target_link_libraries(${PROJECT_NAME} PRIVATE DEMath Rendering ServiceProvider Logging Game GameComponent)
