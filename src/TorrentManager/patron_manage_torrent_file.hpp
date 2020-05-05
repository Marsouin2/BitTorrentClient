#include <iostream>
#include <fstream>
#include <string>

class               PatronManageTorrentFile
{
private:

public:
    PatronManageTorrentFile(){};
    virtual ~PatronManageTorrentFile(){};
    virtual int     OpenAndRead() = 0; // int vraiment necessaire ? sachant qu'on try catch si l'ouverture du fichier = error
    virtual void    GetBencode() = 0;
};