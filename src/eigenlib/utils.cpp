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


#include "utils.h"

VectorXd convertToEigenVector(double* array, size_t size) {
    VectorXd vector(size);

    for (size_t i = 0; i < size; ++i) {
        vector(i) = array[i];
    }

    return vector;
}

MatrixXd convertToEigenMatrix(double** array, size_t size) {
    MatrixXd matrix(size, size);

    for (size_t i = 0; i < size; ++i) {
        for (size_t j = 0; j < size; ++j) {
            matrix(i, j) = array[i][j];
        }
    }

    return matrix;
}
