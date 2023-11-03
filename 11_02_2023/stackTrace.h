#ifndef STACKT_H
#define STACKT_H
#include "linkedStack.h"
#include <string>
#include <stdexcept>

class stackTrace : public std::invalid_argument
{
public:
    stackTrace(std::string msg);
    void push(std::string loc);
    std::string printTrace();

private:
    linkedStack<std::string> trace;
};

#endif