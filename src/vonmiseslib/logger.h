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


#include <stdio.h>
#include <fmt/core.h>
#ifdef USE_OPENMP
    #include <omp.h>
#else
    #include <ctime>
#endif

#define DEBUG(msg, ...) fmt::print(__TIME__ ": DEBUG : " msg "\n", ##__VA_ARGS__)
#define INFO(msg, ...) fmt::print(__TIME__ ": INFO : " msg "\n", ##__VA_ARGS__)
#define WARNING(msg, ...) fmt::print(__TIME__ ": WARNING : " msg "\n", ##__VA_ARGS__)
#define ERROR(msg, ...) fmt::print(__TIME__ ": ERROR : " msg "\n", ##__VA_ARGS__)

using namespace std;

double clocktime();

string deltaTime(const double startTime);
