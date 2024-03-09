add_library(ServiceProvider
                "src/ServiceLocator.cpp")

target_include_directories(ServiceProvider PUBLIC include PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../logging/include)
target_link_libraries(ServiceProvider INTERFACE Logging)
