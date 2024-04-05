import ctypes
import sys
import time
from pathlib import Path

if sys.platform == "win32":
    shared_file_path = Path(sys.prefix, "lib", "eigen.dll")
    eigen_lib = ctypes.CDLL(str(shared_file_path), winmode=0)
elif sys.platform == "linux":
    shared_file_path = Path(sys.prefix, "lib", "libeigen.so")
    eigen_lib = ctypes.CDLL(str(shared_file_path))


class EigenValueProblem:
    def __init__(self, lib):
        self.lib = lib

    def solve(self, A):
        solveEigenValueProblem = self.lib.solveEigenValueProblem
        solveEigenValueProblem.argtypes = [
            ctypes.POINTER(ctypes.POINTER(ctypes.c_double)),
            ctypes.c_int,
        ]
        solveEigenValueProblem.restype = None

        size = len(A)

        A_ptr = (ctypes.POINTER(ctypes.c_double) * size)()
        for i, row in enumerate(A):
            A_ptr[i] = (ctypes.c_double * len(row))(*row)

        start_time = time.time()

        solveEigenValueProblem(A_ptr, size)

        end_time = time.time()
        execution_time = end_time - start_time
        print("Execution time:", execution_time, "seconds")
