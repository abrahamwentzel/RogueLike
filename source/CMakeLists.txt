# Source files.
set(
    source_files
    "source/main.cpp"
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

# Add subdirectories.
add_subdirectory(source/core)
