#pragma once

#include <iostream>
#include <stack>
#include "Exception.h"

template <typename T>
class Stack {
public:

    T pop() {

        try {
            if (thisStack.empty()) {
                throw Exception("the stack is empty ", 3);
            }
            thisStack.pop();
        }
        catch (Exception& exception) {
            printError(exception);
        }
    }

    T push(T value) {

        try {
            if (thisStack.size() >= 100) {
                throw Exception("stack overflow ", 7);
            }
            thisStack.push(value);
        }
        catch (Exception& exception) {
            printError(exception);
        }
    }

    T top() {

        try {
            if (thisStack.empty()) {
                throw Exception("the stack is empty ", 3);
            }
            return thisStack.top();
        }
        catch (Exception& exception) {
            printError(exception);
        }
    }

private:
    std::stack <T> thisStack;
    void printError(Exception& exception) {
        std::cout << "ERROR: " << exception.get_message() << "with exit code "
                  << exception.get_errorCode();
        exit(exception.get_errorCode());
    }
};