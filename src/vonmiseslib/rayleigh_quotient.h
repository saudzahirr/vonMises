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


#ifndef RAYLEIGH_QUOTIENT_H
#define RAYLEIGH_QUOTIENT_H

#include "logger.h"
#include "utils.h"

double rayleighQuotient(const MatrixXd& A, const VectorXd& x);

#endif