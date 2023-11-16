import numpy as np
import nanobind_example as m
import pytest


@pytest.mark.parametrize("index", [1, np.uint32(1)])
def test_uint32(index):
    data = np.array([1.0, 2.0])
    m.swap(data, index)
    assert np.allclose(data, [2.0, 1.0])


@pytest.mark.parametrize("index", [1, np.uint32(1)])
def test_uint32_complex(index):
    data = np.array([1.0 + 2.0j, 3.0 + 4.0j])
    m.swap(data, index)
    assert np.allclose(data, [3.0 + 4.0j, 1.0 + 2.0j])
