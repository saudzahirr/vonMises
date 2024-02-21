import ctypes
import platform


# Load the shared object library
if platform.system() == "Windows":
    eigen_lib = ctypes.CDLL("./lib/eigen.dll")

elif platform.system() == "Linux":
    eigen_lib = ctypes.CDLL("./lib/libeigen.so")
