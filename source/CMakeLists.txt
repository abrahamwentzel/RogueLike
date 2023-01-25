# Source files.
set(
    source_files
    "source/main.cpp"
    "source/Game.cpp"
    "source/GameLoop.cpp"
    "source/Window.cpp"
)

# Executable.
add_executable(RogueLike ${source_files})

# Add include directories.
set(
    includes 
    "source/"
)
target_include_directories(
    RogueLike
    PRIVATE
    ${includes}
)
