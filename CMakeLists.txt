cmake_minimum_required(VERSION 3.22...3.28)
project(vonMises)

set(CMAKE_CXX_STANDARD 11)

if(SKBUILD)
  message(STATUS "The project is built using scikit-build")
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

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC -fopenmp")

add_library(eigen SHARED ${SOURCES})

install(TARGETS eigen LIBRARY DESTINATION lib)
