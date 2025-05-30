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
    src/vonmiseslib/vonMises_API.cpp
    src/vonmiseslib/logger.cpp
    src/vonmiseslib/rayleigh_quotient.cpp
    src/vonmiseslib/utils.cpp
    src/vonmiseslib/von_mises.cpp
)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/src/vonmises/lib)

include_directories(src/vonmises/lib)

# Add subdirectory for third-party libraries
add_subdirectory(src/vonmiseslib/thirdParty)

# Include directories for Eigen and fmt
include_directories(src/vonmiseslib/thirdParty/Eigen_3.4.0)
include_directories(src/vonmiseslib/thirdParty/fmt-10.2.1/include)

configure_file(
  "${PROJECT_SOURCE_DIR}/src/vonmiseslib/version.h.in"
  "${PROJECT_SOURCE_DIR}/src/vonmiseslib/version.h"
)

# Add shared library target for your main project
add_library(vonmises SHARED ${SOURCES})

# Link the fmt static library with your vonmises shared library
target_link_libraries(vonmises PRIVATE fmt)

# Link OpenMP if found
if(OpenMP_CXX_FOUND)
    target_link_libraries(vonmises PRIVATE OpenMP::OpenMP_CXX)
endif()

# Install the vonmises library
install(TARGETS vonmises LIBRARY DESTINATION lib)
