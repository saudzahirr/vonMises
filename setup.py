import sys
from skbuild import setup

cmake_args = []
if sys.platform == "win32":
    cmake_args.append("-G")
    cmake_args.append("MinGW Makefiles")

setup(
    package_data={
        "vonmises": ["lib/*.so"],
    },
    cmake_args=cmake_args,
)
