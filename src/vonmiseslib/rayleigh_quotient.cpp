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


#include "rayleigh_quotient.h"


double rayleighQuotient(const MatrixXd& A, const VectorXd& x) {
    INFO("Calculating eigenvalue using Rayleigh Quotient ...");

    double k = (A * x).dot(x) / x.dot(x);

    DEBUG("Eigenvalue: {}", k);

    return k;
}
