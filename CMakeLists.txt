cmake_minimum_required(VERSION 3.10)

# Project name
project(MiniGolf)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 11)

# Add the source files (all .cpp files in the src folder)
file(GLOB SOURCES "src/*.cpp")

# Create the executable
add_executable(minigolf ${SOURCES})

# Find raylib package and link it
find_package(raylib REQUIRED)
target_link_libraries(minigolf raylib)

# Run target to add make run to the Makefile
add_custom_target(run
    COMMAND ${CMAKE_BINARY_DIR}/minigolf
    DEPENDS minigolf
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Running the MiniGolf game"
)

