#include "utils.h"


double** matrixSub(double** A, double** B, int n, int m) {
    double** C = new double*[n];
    for (int i = 0; i < n; ++i) {
        C[i] = new double[m];
        for (int j = 0; j < m; ++j) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
    return C;
};

double** matrixProduct(double** A, int rowsA, int colsA, double** B, int rowsB, int colsB) {
    if (colsA != rowsB) {
        cerr << "Error: Matrices cannot be multiplied. Invalid dimensions." << endl;
        return nullptr;
    }

    // Dynamically allocate memory for the output matrix
    double** C = new double*[rowsA];
    for (int i = 0; i < rowsA; ++i) {
        C[i] = new double[colsB];
    }

    // Initialize elements of C to 0
    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsB; ++j) {
            C[i][j] = 0.0;
        }
    }

    // Perform matrix multiplication
    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsB; ++j) {
            for (int k = 0; k < colsA; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
};

double** matrixScalarProduct(double** A, int m, int n, double c) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            A[i][j] = c * A[i][j];
        }
    }
    return A;
};


double* vectorProduct(double** A, int rowsA, int colsA, double* v, int rowsB) {
    if (colsA != rowsB) {
        cerr << "Matrix and vector dimensions are not compatible for multiplication.\n";
        return nullptr;
    }

    double* x = new double[rowsA];

    for (int i = 0; i < rowsA; ++i) {
        x[i] = 0.0;
        for (int j = 0; j < colsA; ++j) {
            x[i] += A[i][j] * v[j];
        }
    }
    return x;
};

double** outerProduct(double* vectorA, int m, double* vectorB, int n) {
    double** matrix = new double*[m];
    for (int i = 0; i < m; ++i) {
        matrix[i] = new double[n];
    }

    // Compute the outer product
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = vectorA[i] * vectorB[j];
        }
    }

    return matrix;
}

double Dot(double* vectorA, double* vectorB, int n) {
    double a = 0.0;
    for (int i = 0; i < n; ++i) {
        a += vectorA[i] * vectorB[i];
    }
    return a;
};


double Norm(double* x, int n) {
    return sqrt(Dot(x, x, n));
};

double Max(double* x, int n) {
    double a = 0.0;
    for (int i = 0; i < n; ++i) {
        a = max(x[i], a);
    }
    return a;
};

double Min(double* x, int n) {
    double a = 0.0;
    for (int i = 0; i < n; ++i) {
        a = min(x[i], a);
    }
    return a;
};

double* divideVector(double* v, int n, double s) {
    for (int i = 0; i < n; ++i) {
        v[i] = v[i] / s;
    }
    return v;
};

// Function to clean up the allocated memory for the matrix
void cleanMatrix(double** matrix, int rows) {
    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
};

string getMatrixString(double** matrix, int rows, int cols, int cellSize = 8) {
    stringstream ss;
    
    if (rows < 16) {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                ss << setw(cellSize) << matrix[i][j] << "\t";
            }
            ss << endl;
        }
    }
    else {
        ss << "Matrix written in .out file ..." << endl;
    }
    
    return ss.str();
};

string getVectorString(double* vector, int n) {
    stringstream ss;

    if (n < 16) {
        ss << "[";
        for (int i = 0; i < n; ++i) {
            if (i < n - 1) {
                ss << vector[i] << ", ";
            }
            else {
                ss << vector[i];
            }
        }
        ss << "]";
    }
    else {
        ss << "Vector written in .out file ..." << endl;
    }
    
    return ss.str();
};
