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


#ifndef UTILS_H
#define UTILS_H

#include <Eigen/Dense>

#define ITERATIONS 1000
#define TOLERANCE 1E-32

using namespace std;
using namespace Eigen;

VectorXd convertToEigenVector(double* array, size_t size);
MatrixXd convertToEigenMatrix(double** array, size_t size);

#endif
