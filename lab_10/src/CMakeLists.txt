add_executable (lab_10 main.cpp)

add_custom_target(run_lab_10 DEPENDS lab_10
    COMMAND
        ${CMAKE_CURRENT_BINARY_DIR}/lab_10
)