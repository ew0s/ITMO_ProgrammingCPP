#pragma once

#include <iterator>

template <typename range, typename object>
bool none_of (const range begin, const range end, bool (&func)(object)){
    for (auto it = begin; it != end; it++) {
        if (func(*it))
            return false;
    }
    return true;
}


template <typename range, typename object>
bool is_sorted (range begin, range end, bool (&func)(object, object)){
    range prev_elem = begin;
    for (auto it = begin; it != end; it++) {
        if (!func(*prev_elem, *it))
            return false;
        prev_elem = it;
    }
    return true;
}


template <typename range, typename object>
object find_backward (const range begin, const range end, const object x){
    for (auto it = end; it != begin; it--){
        if (*it == x) {
            return x;
        }
    }
    return object();
}

