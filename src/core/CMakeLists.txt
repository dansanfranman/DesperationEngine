SET(CORE_MODULES
                Logging
                ServiceProvider
   )

foreach(MODULE ${CORE_MODULES})
        message("Adding core module: ${MODULE}")
        add_subdirectory(${MODULE})
        endforeach()
