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

import ctypes
import os
import site
import sys
from pathlib import Path


def get_python_exe():
    return sys.executable


sys_version = f"{sys.version_info.major}{sys.version_info.minor}"
if sys.platform == "win32":
    # shared_file_path = Path(sys.prefix, "lib", "eigen.dll")
    # eigen_lib = ctypes.CDLL(str(shared_file_path), winmode=0)
    shared_file_path = Path(
        get_python_exe(),
        "Lib",
        "site-packages",
        "vonmises",
        "lib",
        "bin",
        "libvonmises.dll",
    )
    os.add_dll_directory(str(shared_file_path))
elif sys.platform == "linux":
    # shared_file_path = Path(sys.prefix, "lib", "libeigen.so")
    # eigen_lib = ctypes.CDLL(str(shared_file_path))
    shared_file_path = Path(
        site.getsitepackages()[0],
        "vonmises",
        "lib",
        "libvonmises.so",
    )

vonmises_lib = ctypes.CDLL(str(shared_file_path), ctypes.RTLD_GLOBAL)
