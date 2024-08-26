#!/usr/bin/env python
import argparse
from vonmises import eigen, lib, utils, __version__
import sys


def main():
    print(f"\033[36mvonMises\033[0m \033[32mv{__version__}\033[0m\n")
    parser = argparse.ArgumentParser(
        description="Numerical Algorithm for Eigen Value Problems", add_help=False
    )
    parser.add_argument(
        "-v", "--version", action="store_true", help="Print vonMises version and exit"
    )
    parser.add_argument("--help", action="store_true", help="Print vonMises help")
    parser.add_argument(
        "-m", "--mat", metavar="MATFILE", type=str, help="Path to the MAT file"
    )
    parser.add_argument(
        "-k",
        "--key",
        metavar="KEY",
        type=str,
        help="Key to access data in the MAT file",
    )
    args = parser.parse_args()

    if args.version:
        sys.exit()

    if args.help:
        print(
            "Eigenvalue Problem Solver: Ax = λx\nUsage: vonMises -m <.mat> -k <key>\n"
        )
        sys.exit()

    if not (args.mat and args.key):
        print("vonMises -m <.mat> -k <key>\n")
        parser.error("You must provide both -m and -k arguments.")

    solver = eigen.EigenValueProblem(lib.vonmises_lib)

    try:
        A = utils.mat_to_array(args.mat, args.key)
        solver.solve(A)
    except ValueError as e:
        print(f"Error: {e}")
        sys.exit(1)


if __name__ == "__main__":
    main()
