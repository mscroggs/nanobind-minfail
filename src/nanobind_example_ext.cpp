#include <nanobind/nanobind.h>
#include <nanobind/ndarray.h>
#include <span>

#include <nanobind/stl/complex.h>



namespace nb = nanobind;

using namespace nb::literals;

namespace {

template <typename T> void swap(std::span<T> data, std::uint32_t index) {
  std::swap(data[0], data[1]);
};
}

NB_MODULE(nanobind_example_ext, m) {
  m.def("swap", [](nb::ndarray<double, nb::ndim<1>, nb::c_contig> data,
                   std::uint32_t index) {
    swap(std::span(data.data(), data.size()), index);
  });
  m.def("swap",
        [](nb::ndarray<std::complex<double>, nb::ndim<1>, nb::c_contig> data,
           std::uint32_t index) {
          swap(std::span(data.data(), data.size()), index);
        });
}
