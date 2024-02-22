#ifndef EIGEN_H
#define EIGEN_H

#ifdef _WIN32
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT
#endif

#include "rayleigh_quotient.h"
#include "von_mises.h"

extern "C" {
    DLLEXPORT void solveEigenValueProblem(double** A, int size);
}

#endif