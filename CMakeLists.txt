# Setup.
cmake_minimum_required(VERSION 3.0)
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR})
project(Init_RogueLike)
set(CMAKE_EXPORT_COMPILE_COMMANDS True)

# Main build.
include("source/CMakeLists.txt")

# Add include directories.
set(
    includes 
    "third-party/bgfx/include/"
)
target_include_directories(
    RogueLike
    PRIVATE
    ${includes}
)

# Add include directories.
set(
    links 
    "third-party/bgfx/src/"
)
target_include_directories(
    RogueLike
    PRIVATE
    ${links}
)

# Build.
set(CMAKE_BUILD_TYPE "Debug")
