import os
import unittest
import numpy as np
from scipy.io import loadmat
from src.utils import array_to_mat

test_mat_key = "A"
test_array = np.array(
    [
        [10.0, -1.0, 2.0, 0.0],
        [-1.0, 11.0, -1.0, 3.0],
        [2.0, -1.0, 10.0, -1.0],
        [0.0, 3.0, -1.0, 8.0],
    ]
)


class TestUtils(unittest.TestCase):
    def test_array_to_mat(self):
        test_matfile_path = "MATRIX.mat"
        array_to_mat(test_array, test_matfile_path, test_mat_key)
        loaded_data = loadmat(test_matfile_path)
        os.remove(test_matfile_path)
        self.assertTrue(np.array_equal(loaded_data[test_mat_key], test_array))


if __name__ == "__main__":
    unittest.main()
