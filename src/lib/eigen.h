#ifndef EIGEN_H
#define EIGEN_H

#include "rayleigh_quotient.h"
#include "von_mises.h"

void solveEigenValueProblem(double** A, double* eigenvalues, double** eigenvectors, int size);

#endif