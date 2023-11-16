import numpy as np
import nanobind_example as m
import pytest

@pytest.mark.parametrize("index", [1, np.uint32(1)])
def test_uint32(index):
    e = m.FiniteElement()

    data = np.array([1.0, 2.0])
    e.swap(data, index)
    assert np.allclose(data, [2.0, 1.0])


@pytest.mark.parametrize("index", [1, np.uint32(1)])
def test_uint32_complex(index):
    e = m.FiniteElement()

    data = np.array([1.0 + 2.0j, 3.0 + 4.0j])
    e.swap(data, index)
    assert np.allclose(data, [3.0 + 4.0j, 1.0 + 2.0j])
