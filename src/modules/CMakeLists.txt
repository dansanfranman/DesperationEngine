set(MODULES
                Rendering
   )

foreach(MODULE ${MODULES})
        message("Adding module: ${MODULE}")
        add_subdirectory(${MODULE})
        endforeach()
