#include "Algorithms.h"


template <typename range>
bool none_of (const range begin, const range end, bool &func){
    for (auto it = begin; it != end; it++) {
        if (!func(*it))
            return false;
    }
    return true;
}

/*template <typename range>
bool is_sorted (range begin, range end){
    range prev_elem = begin;
    for (auto it = begin; it != end; it++) {
        if (!isSorted(*prev_elem, *it))
            return false;
        prev_elem = it;
    }
    return true;
}*/

/*template <typename range, typename object>
object find_backward (range begin, range end, object x){
    for (auto it = end; it != begin; it--){
        if (*it == x) {
            return it;
        }
    }
    return -1;
}*/

