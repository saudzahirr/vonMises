# vonMises

vonMises is a numerical algorithm for solving eigenvalue problems using the deflation method and power iteration. It is implemented in C++ and wrapped for Python using [scikit-build](https://scikit-build.readthedocs.io/) (skbuild) to provide a high-performance solution for eigenvalue computations in Python environments.

## Features

- Solves eigenvalue problems using **Von Mises iteration** and **Rayleigh Quotient** methods.
- Supports deflation for computing multiple eigenvalues and eigenvectors.
- High-performance implementation using **Eigen3** and **OpenMP**.
- Extensive logging and debugging support via the **fmt** library.

## Installation

You can install vonMises via pip:

```bash
pip install vonMises
```

Make sure you have the required dependencies in your environment, especially **Eigen3** and **fmt** libraries.

## Building from Source

To build vonMises from source, ensure you have **CMake**, **Eigen3**, and **fmt** installed. The project uses **scikit-build** to handle the Python build and installation process. You can clone the repository and build the project as follows:

```bash
git clone https://github.com/your-username/vonMises.git
cd vonMises
pip install .
```

## License

vonMises is licensed under the MIT License. See [LICENSE](LICENSE) for details.

## Contributing

Contributions are welcome! Feel free to submit issues or pull requests.
