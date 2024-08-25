/*
 * Copyright (c) 2024 Saud Zahir
 *
 * This file is part of vonMises.
 *
 * vonMises is free software; you can redistribute it and/or
 * modify it under the terms of the MIT License.
 *
 * vonMises is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the MIT
 * License for more details.
 */


#ifndef EIGEN_H
#define EIGEN_H

#ifdef _WIN32
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT
#endif

#include <omp.h>

#include "rayleigh_quotient.h"
#include "von_mises.h"
#include "version.h"

extern "C" {
    DLLEXPORT void solveEigenValueProblem(double** A, size_t size, double* eigenvalues, double** eigenvectors);
}

#endif
