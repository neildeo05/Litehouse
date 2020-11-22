#include <pybind11/pybind11.h>
#include "Tensor.cpp"

int Fromulus() {
  Litehouse::Tensor t = Litehouse::Tensor::randarr(3,3);
  return t(0,0);
}

namespace py = pybind11;
PYBIND11_MODULE(main,m) {
  m.def("Fromulus", &Fromulus, "mult 2 nums");
}
