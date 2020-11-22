from setuptools import setup
from pybind11.setup_helpers import Pybind11Extension, build_ext
from pybind11 import get_cmake_dir


setup(name='main',
        ext_modules=[Pybind11Extension("main", ["main.cpp"])],
        cmdclass={'build_ext': build_ext}
        )

