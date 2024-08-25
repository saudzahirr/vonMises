# Add fmt library with -fPIC
add_library(fmt STATIC
    fmt-10.2.1/src/format.cc
)

# Specify include directories for fmt
target_include_directories(fmt PUBLIC fmt-10.2.1/include)

# Ensure fmt is built with -fPIC for compatibility with shared libraries
set_target_properties(fmt PROPERTIES POSITION_INDEPENDENT_CODE ON)
