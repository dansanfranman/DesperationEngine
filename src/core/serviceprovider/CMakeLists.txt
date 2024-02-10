add_library(ServiceProvider
                "src/ServiceLocator.cpp")

target_include_directories(ServiceProvider PRIVATE "include" "${CMAKE_CURRENT_SOURCE_DIR}/../logging/include")

target_link_libraries(ServiceProvider INTERFACE Logging)
