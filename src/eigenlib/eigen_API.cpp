#include "eigen_API.h"


void solveEigenValueProblem(double** A, int size) {
    // Power Iteration with Deflation
    for (int i = 0; i < size; i++) {
        double* x = VonMisesIterationMethod(A, size);
        double c = RayleighQuotient(A, x, size);
        DEBUG_OUTFILE("*EIGEN_VALUE: " + to_string(c));
        DEBUG_OUTFILE("*EIGEN_VECTOR: " + getVectorString(x, size));
        cout << endl;
        A = matrixSub(A, matrixScalarProduct(outerProduct(x, size, x, size), size, size, c), size, size);
        delete[] x;
    }
}
