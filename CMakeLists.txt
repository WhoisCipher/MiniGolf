cmake_minimum_required(VERSION 3.10)

project(MiniGolf)

# Set C standards
set(CMAKE_C_STANDARD 99)

# Find Raylib package (make sure Raylib is installed in your system)
find_package(raylib REQUIRED)

# Define the executable
add_executable(minigolf main.c)

# Link the Raylib library
target_link_libraries(minigolf raylib)

# run target that adds make run to the Makefile
add_custom_target(run
    COMMAND ${CMAKE_BINARY_DIR}/minigolf
    DEPENDS minigolf
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Running the MiniGolf game"
)

