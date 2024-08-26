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


#include "von_mises.h"


VectorXd vonMisesIterationMethod(const MatrixXd& A) {

    INFO("Starting Von Mises Method ...");
    INFO("Initializing random vector for Von Mises iteration ...");

    int n = A.rows();
    VectorXd x = VectorXd::Zero(n);
    VectorXd u = VectorXd::Zero(n);

    random_device rd;
    mt19937 gen(rd());

    // Mean and standard deviation for the normal distribution
    double mean = 0.5;  // Center around 0.5 for values between 0 and 1
    double stddev = 0.25;  // Standard deviation, adjust as needed

    normal_distribution<double> distribution(mean, stddev);

    // Generate random numbers from the normal distribution
    for (size_t i = 0; i < n; ++i) {
        double random_number = distribution(gen);
        random_number = max(0.0, min(1.0, random_number));
        x(i) = random_number;
    }

    // Von Mises iterative formula
    for (int a = 1; a <= ITERATIONS; ++a) {
        u = x;
        x = A * x;  // Matrix-vector multiplication
        x.normalize();  // Normalize the vector

        double epsilon = (x - u).norm();
        if (epsilon == 0 || epsilon < TOLERANCE) {
            DEBUG("Dominant Eigenvector converged at {} iterations.", a);

            return x;
        }
    }

    return x;
}
