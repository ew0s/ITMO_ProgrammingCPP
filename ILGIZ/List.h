#pragma once

struct elem {

    int numb_;
    elem* next_ = nullptr;
    elem* prev_ = nullptr;
};

class List {

public:

    List();

    void push(int numb);

    int last();

    void swap();

private:

    elem list_;
};