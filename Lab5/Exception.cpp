#include <iostream>
#include "Exception.h"


Exception::Exception(string message_, int exceptionCode_)
{
    message = message_;
    exceptionCode = exceptionCode_;
}

int Exception::getExceptionCode()
{
    return exceptionCode;
}

void Exception::printMessage()
{
    cout << message;
}