#pragma once

#include "StackT.h"
#include "SearchMaxT.h"
#include "Exception.h"
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
    Array <int> array_;
    Stack <100, int> stack_;
};