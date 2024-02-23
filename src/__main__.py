import argparse
from src import eigen, utils
import sys


def main():
    parser = argparse.ArgumentParser(
        description="Solve eigenvalue problem from a MAT file"
    )
    parser.add_argument(
        "-m",
        "--mat",
        metavar="MATFILE",
        type=str,
        help="Path to the MAT file",
        required=True,
    )
    parser.add_argument(
        "-k",
        "--key",
        metavar="KEY",
        type=str,
        help="Key to access data in the MAT file",
        required=True,
    )
    args = parser.parse_args()

    solver = eigen.EigenValueProblem(eigen.eigen_lib)

    try:
        A = utils.mat_to_array(args.mat, args.key)
        solver.solve(A)
    except ValueError as e:
        print(f"Error: {e}")
        sys.exit(1)


if __name__ == "__main__":
    main()
