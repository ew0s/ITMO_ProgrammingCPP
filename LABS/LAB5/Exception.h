#pragma once

class Exception {
private:
    const char* error_message_;
    int error_numb_;

public:
    Exception(const char* error_message, int error_numb);

    const char* get_message();

    int get_errorCode();
};