# Source files.
set(
    source_files
    "source/core/Game.cpp"
    "source/core/GameLoop.cpp"
)
target_sources(RogueLike PRIVATE ${source_files})

# Include files.
set(
    includes 
    "source/core/"
)
target_include_directories(
    RogueLike
    PRIVATE
    ${includes}
)
