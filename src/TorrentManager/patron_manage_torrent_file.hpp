class               PatronManageTorrentFile
{
private:

public:
    PatronManageTorrentFile(){};
    virtual ~PatronManageTorrentFile(){};
    virtual void    OpenAndRead() = 0;
    virtual void    GetBencode() = 0;
};