import unittest
import numpy as np
from src.utils import mat_to_array

test_matfile_path = "test/test-data/MATRIX.mat"
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
    def test_mat_to_array(self):
        loaded_array = mat_to_array(test_matfile_path, test_mat_key)
        self.assertTrue(np.array_equal(loaded_array, test_array))


if __name__ == "__main__":
    unittest.main()
