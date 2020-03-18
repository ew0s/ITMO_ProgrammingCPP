#pragma once

#include "StackT.h"
#include "SearchMaxT.h"
#include <vector>

enum ArrayActions {
    ADD_ELEMENT = 1,
    FIND_MAX = 2
};

enum StackActions {
  SHOW_TOP = 1,
  POP_ELEMENT = 2,
  PUSH_ELEMENT = 3
};

class menu {
public:

    void getAction();

    void get_action_stack();

    void get_action_array();

private:
    Stack <int> stack_;
    std::vector <int> array_;
};