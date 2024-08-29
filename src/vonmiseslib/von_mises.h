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


#ifndef VON_MISES_H
#define VON_MISES_H

#include <Eigen/Dense>
#include <random>

#include "logger.h"
#include "utils.h"

using namespace Eigen;

VectorXd vonMisesIterationMethod(const MatrixXd& A);

#endif // VON_MISES_H
