#include "Exception.h"

Exception::Exception(const char *error_message, int error_numb)
    : error_message_(error_message)
    , error_numb_(error_numb){
}

const char * Exception::get_message() {
    return error_message_;
}

int Exception::get_errorCode() {
    return error_numb_;
}