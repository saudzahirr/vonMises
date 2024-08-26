"""
Copyright (c) 2024 Saud Zahir

This file is part of vonMises.

vonMises is free software; you can redistribute it and/or
modify it under the terms of the MIT License.

vonMises is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the MIT
License for more details.
"""

import numpy as np
from scipy.io import loadmat, savemat


def mat_to_array(matfile_path, mat_key):
    """
    Load data from a MAT file and return as a NumPy array with dtype=np.double.

    Args:
        matfile_path (str): Path to the MAT file.
        mat_key (str): Key to access the matrix in the MAT file.

    Returns:
        numpy.ndarray: NumPy array containing the data from the MAT file.

    Raises:
        ValueError: If no matrix found in the MAT file.
    """
    with open(matfile_path, "rb") as f:
        mat_data = loadmat(f)

    if mat_key not in mat_data:
        raise ValueError(f"Key '{mat_key}' not found in the MAT file.")

    matrix = mat_data[mat_key]
    if not isinstance(matrix, np.ndarray):
        raise ValueError(f"Data associated with key '{mat_key}' is not a NumPy array.")

    return np.array(matrix, dtype=np.double)


def array_to_mat(array, matfile_path, mat_key):
    """
    Save a NumPy array as a MATLAB matrix in a MAT file.

    Args:
        array (numpy.ndarray): NumPy array to be saved.
        matfile_path (str): Path to the MAT file.
        mat_key (str): Key to store the matrix in the MAT file.
    """
    savemat(matfile_path, {mat_key: array})
