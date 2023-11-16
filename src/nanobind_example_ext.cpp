#include <nanobind/nanobind.h>
#include <nanobind/ndarray.h>
#include <span>

#include <nanobind/stl/complex.h>



namespace nb = nanobind;

using namespace nb::literals;

namespace {

class FiniteElement {
  public:
    FiniteElement() {}

    template<typename T>
    void swap(std::span<T> data) const {
        std::swap(data[0], data[1]);
    }

};

}

NB_MODULE(nanobind_example_ext, m) {
    nb::class_<FiniteElement>(m, "FiniteElement")
      .def("__init__", [](const FiniteElement& self) { FiniteElement(); })
      .def(
          "swap",
          [](const FiniteElement& self,
             nb::ndarray<double, nb::ndim<1>, nb::c_contig> data)
          {
            self.swap(std::span(data.data(), data.size()));
          })
      .def(
          "swap",
          [](const FiniteElement& self,
             nb::ndarray<std::complex<double>, nb::ndim<1>, nb::c_contig> data)
          {
            self.swap(std::span(data.data(), data.size()));
          });
}
