#ifndef UTILS_H
#define UTILS_H

#include <cmath>
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

#define ITERATIONS 1000
#define TOLERANCE 1E-32
#define PI M_PI


double** matrixSub(double** A, double** B, int n, int m);

double** matrixProduct(double** A, int rowsA, int colsA, double** B, int rowsB, int colsB);

double** matrixScalarProduct(double** A, int m, int n, double c);

double* vectorProduct(double** A, int rowsA, int colsA, double* v, int rowsB);

double** outerProduct(double* vectorA, int m, double* vectorB, int n);

double Dot(double* vectorA, double* vectorB, int n);

double Norm(double* x, int n);

double Max(double* x, int n);

double Min(double* x, int n);

double* divideVector(double* v, int n, double s);

void cleanMatrix(double** matrix, int rows);

string getMatrixString(double** matrix, int rows, int cols, int cellSize);

string getVectorString(double* vector, int n);


#endif
