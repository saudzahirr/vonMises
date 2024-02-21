#include "eigen.h"


void solveEigenValueProblem(double** A, double* eigenvalues, double** eigenvectors, int size) {
    // Power Iteration with Deflation
    for (int i = 0; i < size; i++) {
        double* x = VonMisesIterationMethod(A, size);
        double c = RayleighQuotient(A, x, size);
        WARNING_OUT("Eigenvalue: " + to_string(c));
        WARNING_OUT("Eigenvector: " + getVectorString(x, size));
        cout << endl;
        A = matrixSub(A, matrixScalarProduct(outerProduct(x, size, x, size), size, size, c), size, size);
        eigenvalues[i] = c;
        for (int j = 0; j < size; j++) {
            eigenvectors[j][i] = x[j];
        }
        delete[] x;
    }
}

int main() {
    const int n = 4;

    double** A = new double*[n];
    double* eigenvalues = new double[n];
    double** eigenvectors = new double*[n];
    for (int i = 0; i < n; ++i) {
        A[i] = new double[n];
        eigenvectors[i] = new double[n];
    }

    A[0][0] = 10.0; A[0][1] = -1.0; A[0][2] = 2.0; A[0][3] = 0;
    A[1][0] = -1.0; A[1][1] = 11.0; A[1][2] = -1.0; A[1][3] = 3.0;
    A[2][0] = 2.0; A[2][1] = -1.0; A[2][2] = 10.0; A[2][3] = -1.0;
    A[3][0] = 0.0; A[3][1] = 3.0; A[3][2] = -1.0; A[3][3] = 8.0;

    clock_t time_req;
    time_req = clock();

    solveEigenValueProblem(A, eigenvalues, eigenvectors, n);
    time_req = clock() - time_req;
    DEBUG_OUT("Execution time for calculating eigenvalues and eigenvectors using Von Mises iteration and Rayleigh quotient algorithm: "
            + to_string(time_req/CLOCKS_PER_SEC) + " seconds");

    // Clean up
    for (int i = 0; i < n; ++i) {
        delete[] A[i];
        delete[] eigenvectors[i];
    }
    delete[] A;
    delete[] eigenvalues;
    delete[] eigenvectors;

    return 0;
}
