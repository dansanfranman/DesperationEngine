SET(CORE_MODULES
                Logging
                ServiceProvider
                DEMath
   )

foreach(MODULE ${CORE_MODULES})
        message("Adding core module: ${MODULE}")
        add_subdirectory(${MODULE})
        endforeach()
