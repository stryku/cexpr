#pragma once

#include "cexpr/array.hpp"

namespace cexpr
{
    namespace detail
    {
        template<class T>
        constexpr void swap(T& l, T& r)
        {
            T tmp = std::move(l);
            l = std::move(r);
            r = std::move(tmp);
        }

        template <typename T, size_t N>
        constexpr void sort(array<T, N> &array, size_t left, size_t right)
        {
            if (left < right)
            {
                size_t m = left;

                for (size_t i = left + 1; i<right; i++)
                    if (array[i]<array[left])
                        swap(array[++m], array[i]);

                swap(array[left], array[m]);

                sort(array, left, m);
                sort(array, m + 1, right);
            }
        }
    }
}