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


#include "logger.h"

double clocktime() {
    #ifdef USE_OPENMP
        return omp_get_wtime();
    #else
        return clock();
    #endif
}

string deltaTime(const double startTime) {
    #ifdef USE_OPENMP
        return fmt::format("{:e}s", omp_get_wtime() - startTime);
    #else
        return fmt::format("{:e}s", (clock() - startTime)/CLOCKS_PER_SEC);
    #endif
}
