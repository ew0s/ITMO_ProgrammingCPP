#pragma once

struct elem {

    int numb_ = -1;
    elem* next_ = nullptr;
    elem* prev_ = nullptr;
};

class List {

public:

    List();

    void push(int);

    int last();

    void swap();

    int get(int);

private:

    elem list_;
    elem* top_;
    elem* last_;
    unsigned int length_;

};