#include "stackTrace.h"

stackTrace::stackTrace(std::string msg) : invalid_argument(msg)
{
}

void stackTrace::push(std::string loc)
{
    trace.push(loc);
}

std::string stackTrace::printTrace()
{
    std::string out;
    linkedStack<std::string> temp;
    while (!trace.isEmptyStack())
    {
        std::string t = trace.pop();
        out += t + "\n";
        temp.push(t);
    }
    while (!temp.isEmptyStack())
    {
        trace.push(temp.pop());
    }
    return out;
}
