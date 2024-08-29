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


#include "vonMises_API.h"

/**
 * @file
 * Eigen value problem solver using deflation method power iteration
 */

void solveEigenValueProblem(double** A, size_t size, double* eigenvalues, double** eigenvectors) {
    INFO("----------------------------------------------");
    INFO("CMake Version   :: {}", CMake_VERSION);
    INFO("GCC Version     :: {}", gcc_VERSION);
    INFO("OMP max threads :: {}", omp_get_max_threads());
    INFO("----------------------------------------------");

    MatrixXd _A =  convertToEigenMatrix(A, size);
    // Power Iteration with Deflation
    for (size_t a = 0; a < size; a++) {
        double start_time = clocktime();
        VectorXd x = vonMisesIterationMethod(_A);
        DEBUG("Execution time for Von Mises Method: {} seconds", deltaTime(start_time));
        start_time = clocktime();
        double c = rayleighQuotient(_A, x);
        DEBUG("Execution time for Rayleigh Quotient Method: {} seconds", deltaTime(start_time));
        // Store the computed eigenvalue
        eigenvalues[a] = c;

        // Store the eigenvector
        for (size_t i = 0; i < size; i++) {
            eigenvectors[a][i] = x(i);
        }
        _A = _A - c * (x * x.transpose());
    }
}
