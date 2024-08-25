cmake_minimum_required(VERSION 3.22...3.28)
project(vonMises)

set(CMAKE_CXX_STANDARD 11)

if(SKBUILD)
  message(STATUS "The project is built using scikit-build")
endif()

# Find and configure OpenMP
find_package(OpenMP REQUIRED)

if(OpenMP_CXX_FOUND)
    message(STATUS "OpenMP found and enabled")
    add_definitions(-DUSE_OPENMP)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
endif()

set(SOURCES
    src/eigenlib/eigen_API.cpp
    src/eigenlib/logger.cpp
    src/eigenlib/rayleigh_quotient.cpp
    src/eigenlib/utils.cpp
    src/eigenlib/von_mises.cpp
)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/src/lib)

include_directories(src/lib)

# Add subdirectory for third-party libraries
add_subdirectory(src/eigenlib/thirdParty)

# Include directories for Eigen and fmt
include_directories(src/eigenlib/thirdParty/Eigen_3.4.0)
include_directories(src/eigenlib/thirdParty/fmt-10.2.1/include)

configure_file(
  "${PROJECT_SOURCE_DIR}/src/eigenlib/version.h.in"
  "${PROJECT_SOURCE_DIR}/src/eigenlib/version.h"
)

# Add shared library target for your main project
add_library(eigen SHARED ${SOURCES})

# Link the fmt static library with your eigen shared library
target_link_libraries(eigen PRIVATE fmt)

# Link OpenMP if found
if(OpenMP_CXX_FOUND)
    target_link_libraries(eigen PRIVATE OpenMP::OpenMP_CXX)
endif()

# Install the eigen library
install(TARGETS eigen LIBRARY DESTINATION lib)
