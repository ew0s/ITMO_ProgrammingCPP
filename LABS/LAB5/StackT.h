#pragma once

#include <iostream>
#include <stack>
#include "Exception.h"

template <typename T>
class Stack {
public:

    void pop() {

        if (thisStack.empty()) {
            throw Exception("the stack is empty ");
        }
        thisStack.pop();
    }

    void push(T value) {

        if (thisStack.size() >= 100) {
            throw Exception("stack overflow");
        }
        thisStack.push(value);
    }

    T top() {

        if (thisStack.empty()) {
            throw Exception("the stack is empty");
        }
        return thisStack.top();
    }

private:
    std::stack <T> thisStack;
};