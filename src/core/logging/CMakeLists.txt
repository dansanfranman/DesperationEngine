add_library(Logging
                src/WindowsLoggerProvider.cpp
           )

target_include_directories(Logging PUBLIC "include") 

