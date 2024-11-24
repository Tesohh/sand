cmake_minimum_required(VERSION 3.10)

# Project name and version
project(sand VERSION 1.0 LANGUAGES C)

# Set C standard to C99
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Enable stricter warnings for GCC/Clang
if(CMAKE_C_COMPILER_ID MATCHES "Clang|GNU")
    add_compile_options(-Wall -Wextra -pedantic)
endif()

# Find raylib (installed via Homebrew)
find_package(raylib REQUIRED)

# Collect all .c and .h files in the src/ directory and its subdirectories
file(GLOB_RECURSE SOURCES "${CMAKE_SOURCE_DIR}/src/*.c")
file(GLOB_RECURSE HEADERS "${CMAKE_SOURCE_DIR}/src/*.h")

# Add the executable target
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# Link raylib to the executable
target_link_libraries(${PROJECT_NAME} raylib)

# Include directories for headers
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/src)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/src/game)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/src/element)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/src/grain)

# macOS-specific: Link additional system frameworks required by raylib
if(APPLE)
    target_link_libraries(${PROJECT_NAME}
        "-framework OpenGL"
        "-framework Cocoa"
        "-framework IOKit"
        "-framework CoreVideo"
    )
endif()
