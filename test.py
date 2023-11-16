import numpy as np
import nanobind_example as m


def test_uint32():
    e = m.FiniteElement()

    data = np.array([1.0, 2.0])
    e.swap(data)
    assert np.allclose(data, [2.0, 1.0])


def test_uint32_complex():
    e = m.FiniteElement()

    data = np.array([1.0 + 2.0j, 3.0 + 4.0j])
    e.swap(data)
    assert np.allclose(data, [3.0 + 4.0j, 1.0 + 2.0j])
