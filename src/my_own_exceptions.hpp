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