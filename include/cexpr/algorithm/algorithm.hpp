#pragma once

#include "cexpr/algorithm/detail/detail.hpp"

#include <utility>

namespace cexpr
{
    template<class T>
    constexpr void swap(T& l, T& r)
    {
        detail::swap(l, r);
    }

    template <typename T, size_t N>
    constexpr array<T, N> sort(array<T, N> array)
    {
        cexpr::array::array<T, N> sorted = array;

        detail::sort(sorted, 0, N);

        return sorted;
    }
}
