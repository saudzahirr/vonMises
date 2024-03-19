cmake_minimum_required(VERSION 3.28)
project(vonMises)


set(CMAKE_CXX_STANDARD 11)


set(SOURCES
    src/lib/eigen.cpp
    src/lib/logger.cpp
    src/lib/rayleigh_quotient.cpp
    src/lib/utils.cpp
    src/lib/von_mises.cpp
)

include_directories(src/lib)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC -fopenmp")


add_library(eigenlib SHARED ${SOURCES})
