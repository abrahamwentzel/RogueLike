# Source files.
set(
    source_files
)
target_sources(RogueLike PRIVATE ${source_files})

# Include files.
set(
    includes 
    "source/test/"
)
target_include_directories(
    RogueLike
    PRIVATE
    ${includes}
)
