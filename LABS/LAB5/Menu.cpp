#include <iostream>
#include "Menu.h"
#include <vector>


void menu::getAction() {
    std::cout << "What type do you want to work with ?\n";
    std::cout << "Array - 1\n";
    std::cout << "Stack - 2\n";
    std::cout << "EXIT FROM PROGRAM - 3\n";
    unsigned int type = 0;
    try {
        std::cin >> type;
        if (type <= 0 || type > 3) {
            throw ("/----------WRONG SELECTION");
        }
    }
    catch (const char* message) {
        std::cout << message << " SELECT ACTION AGAIN----------/\n";
        getAction();
    }

    switch (type) {
        case 1: {
            get_action_array();
            break;
        }

        case 2: {
            get_action_stack();
            break;
        }

        default:
            std::cout << "BYE - BYE\n";
            exit(0);
    }
}

void menu::get_action_stack() {
    std::cout << "/--------------------SELECT_STACK_ACTIONS--------------------/\n";
    std::cout << "SHOW TOP - 1\n";
    std::cout << "POP_ELEMENT - 2\n";
    std::cout << "PUSH_ELEMENT - 3\n";

    int temp = 0;
    try {
        std::cin >> temp;
        if (temp < 0 || temp > 3) {
            throw ("/----------WRONG SELECTION");
        }
    }
    catch (const char* message) {
        std::cout << message << " SELECT ACTION AGAIN----------/\n";
        getAction();
    }

    switch  (temp) {
        case SHOW_TOP: {
            std::cout << stack_.top() << "\n";
            getAction();
            break;
        }

        case POP_ELEMENT: {
            stack_.pop();
            getAction();
            break;
        }

        default: {
            std::cout << "Enter numb: ";
            int numb;
            std::cin >> numb;
            stack_.push(numb);
            getAction();
        }
    }
}


void menu::get_action_array() {
    std::cout << "/--------------------SELECT_ARRAY_ACTIONS--------------------/\n";
    std::cout << "ADD ELEMENT - 1\n";
    std::cout << "FIND MAX - 2\n";
    int temp;
    try {
        std::cin >> temp;
        if (temp < 0 || temp > 2) {
            throw ("/----------WRONG SELECTION");
        }
    }
    catch (const char* message) {
        std::cout << message << " SELECT ACTION AGAIN----------/\n";
        getAction();
    }


    if (temp == 2) {
        findMaximal(array_, 3);
        getAction();
    }

    else {
        std::cout << "Enter numb: ";
        int value;
        std::cin >> value;
        push(array_, value);
        getAction();
    }
}

