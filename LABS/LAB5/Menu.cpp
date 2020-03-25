#include <iostream>
#include "Menu.h"
#include <vector>


void menu::getAction() {
    std::cout << "What type do you want to work with ?\n";
    std::cout << "Array - 1\n";
    std::cout << "Stack - 2\n";
    std::cout << "EXIT FROM PROGRAM - 3\n";

    unsigned int type;
    try {
        std::cin >> type;
        if (type <= 0 || type > 3) {
            throw ("/----------WRONG SELECTION SELECT ACTION AGAIN----------/\n");
        }
    }

    catch (const char* message) {
        std::cout << message;
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

void printError(Exception& exception) {
    std::cout << "ERROR: " << exception.what();
    exit(3);
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
            throw ("/----------WRONG SELECTION SELECT ACTION AGAIN----------/\n");
        }
    }

    catch (const char* message) {
        std::cout << message;
        getAction();
    }

    switch  (temp) {

        case SHOW_TOP: {

            try {
                std::cout << stack_.top() << "\n";
                getAction();
                break;
            }

            catch (Exception& exception) {
                printError(exception);
            }
        }

        case POP_ELEMENT: {

            try {
                stack_.pop();
                getAction();
                break;
            }

            catch (Exception& exception) {
                printError(exception);
            }
        }

        case PUSH_ELEMENT: {

            try {
                std::cout << "Enter numb: ";
                int numb = -1;
                std::cin >> numb;
                stack_.push(numb);
                getAction();
            }

            catch (Exception& exception) {
                printError(exception);
            }
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
            throw ("/----------WRONG SELECTION SELECT ACTION AGAIN----------/\n");
        }
    }

    catch (const char* message) {
        std::cout << message;
        getAction();
    }

    if (temp == FIND_MAX) {
        array_.findMaximal();
        getAction();
    }

    else if (temp == ADD_ELEMENT){
        std::cout << "Enter numb: ";
        int numb;
        std::cin >> numb;
        array_.push(numb);
        getAction();
    }
}

