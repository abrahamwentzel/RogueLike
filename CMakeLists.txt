# Setup.
cmake_minimum_required(VERSION 3.0)
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR})
project(Init_RogueLike)
set(CMAKE_EXPORT_COMPILE_COMMANDS True)
add_compile_definitions(BX_CONFIG_DEBUG)

# Main build.
include("source/CMakeLists.txt")

# Add include directories.
set(
    includes 
    "third-party/bgfx/include/"
    "third-party/bx/include/"
    "third-party/glfw/include/"
    "third-party/glad/include/"
)
target_include_directories(
    RogueLike
    PRIVATE
    ${includes}
)

# Add source directories.
set(
    links 
    "third-party/bgfx/src/"
    "third-party/bx/src/"
    "third-party/glfw/src/"
    "third-party/glad/src/"
)
target_link_directories(
    RogueLike
    PRIVATE
    ${links}
)

# Build.
set(CMAKE_BUILD_TYPE "Debug")
