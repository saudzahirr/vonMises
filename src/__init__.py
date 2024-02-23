import pkg_resources

__version__ = pkg_resources.get_distribution("vonMises").version

from src.eigen import *
from src.utils import *
