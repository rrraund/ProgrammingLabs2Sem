#pragma once
#include <exception>
#include <string>

using namespace std;


class Exception
{
private:
    string message;
    int exceptionCode;

public:
    Exception(string, int);
    int getExceptionCode();
    void printMessage();
};