#pragma once


template <typename range>
bool none_of (range, range, bool &func);

template <typename range>
bool is_sorted (range, range);

template <typename range, typename object>
object find_backward (range, range, object);

