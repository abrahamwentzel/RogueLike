# Source files.
set(
    source_files
    "source/main.cpp"
    "source/test.cpp"
)

# Executable.
add_executable(RogueLike ${source_files})

# Add subdirectories.
add_subdirectory(source/test)
