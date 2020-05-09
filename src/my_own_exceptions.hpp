#ifndef MY_OWN_EXCEPTIONS_HPP_
#define MY_OWN_EXCEPTIONS_HPP_

#include <string>

class                   MyOwnExceptions
{
private:
    std::string         msg;
public:
    MyOwnExceptions(const std::string& msg_) : msg(msg_) {}
    ~MyOwnExceptions() {}
    std::string GetErrorMessage() const {
        return(msg);
    }
};

#endif /* MY_OWN_EXCEPTIONS_HPP_ */