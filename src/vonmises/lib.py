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
import sys
from pathlib import Path


sys_version = f"{sys.version_info.major}{sys.version_info.minor}"
if sys.platform == "win32":
    shared_file_path = Path(
        sys.prefix,
        "bin",
        "libvonmises.dll",
    )
    vonmises_lib = ctypes.CDLL(str(shared_file_path), winmode=0)
elif sys.platform == "linux":
    shared_file_path = Path(sys.prefix, "lib", "libvonmises.so")
    vonmises_lib = ctypes.CDLL(str(shared_file_path), ctypes.RTLD_GLOBAL)
