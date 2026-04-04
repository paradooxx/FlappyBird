cmake_minimum_required(VERSION 3.10)
project(FlappyBird C)

# Use C11
set(CMAKE_C_STANDARD 11)

# Include directories for headers
include_directories(${PROJECT_SOURCE_DIR}/src/include)

# Link directories for SDL2 libraries
link_directories(${PROJECT_SOURCE_DIR}/src/lib)

# Collect all C source files
file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/src/*.c")

# Create the executable
add_executable(flappybird ${SOURCES})

# Link libraries in the same order as your working tasks.json
# -lmingw32 -lSDL2main -lSDL2
target_link_libraries(flappybird mingw32 SDL2main SDL2)

# Add GUI subsystem flag (like -mwindows in GCC)
if(MINGW)
    set_target_properties(flappybird PROPERTIES LINK_FLAGS "-mwindows")
endif()