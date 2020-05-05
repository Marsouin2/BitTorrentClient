class               PatronNetwork
{
private:

public:
    PatronNetwork(void);
    virtual ~PatronNetwork(void);
    virtual void    Connect() = 0;
    virtual void    Send() = 0;
    virtual void    Receive() = 0;
};