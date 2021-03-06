add_executable (lab_1 main.cpp)

add_custom_target(run_lab_1 DEPENDS template
    COMMAND
        ${CMAKE_CURRENT_BINARY_DIR}/template
)