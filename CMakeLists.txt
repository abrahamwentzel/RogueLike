# Setup.
cmake_minimum_required(VERSION 3.1)
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_EXPORT_COMPILE_COMMANDS True) # For the LSP.
project(Build_RogueLike)

# Find OpenGL.
find_package(OpenGL REQUIRED)

# Find X11
find_package(X11 REQUIRED)

# BGFX.
add_compile_definitions(BX_CONFIG_DEBUG)

# GLFW.
set( GLFW_BUILD_DOCS OFF CACHE BOOL "GLFW lib only" )
set( GLFW_INSTALL OFF CACHE BOOL "GLFW lib only" )
add_subdirectory(third-party/glfw)

# MSVC.
if( MSVC )
    SET( CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /ENTRY:mainCRTStartup" )
endif()

# RogueLike.
include("source/CMakeLists.txt")

# Add include directories.
set(
    includes 
    "third-party/bgfx/include/"
    "third-party/bx/include/"
    "third-party/bimg/include/"
    "third-party/bnet/include/"
    "third-party/glfw/include/"
    "assets/"
    ${OPENGL_INCLUDE_DIRS}
)
target_include_directories(
    RogueLike
    PRIVATE
    ${includes}
)

# Link directories.
set(
    links
    "third-party/bgfx/.build/linux64_gcc/bin/"
)
target_link_directories(
    RogueLike    
    PRIVATE
    ${links}
)

# Add link libraries.
set(
    libs
    glfw
    X11
    bgfxRelease
    bimgRelease
    bxRelease
    ${OPENGL_LIBRARIES}
    ${X11_LIBRARIES}
)
target_link_libraries(
    RogueLike 
    ${libs}
)

# MSVC.
if(MSVC)
    set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT RogueLike)
endif()

# Build type.
set(CMAKE_BUILD_TYPE "Debug")
# set(CMAKE_BUILD_TYPE "Release")
