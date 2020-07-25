#include "network.hpp"

Network::Network(const std::string &url_request) {
    this->Connect(url_request);
}

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

void                Network::Connect(const std::string &url_request) {
    CURL *curl;
    CURLcode res;
    std::string readBuffer;

    curl = curl_easy_init();
    if(curl) {
        /* First set the URL that is about to receive our POST. This URL can just as well be a https:// URL if that is what should receive the data. */
        curl_easy_setopt(curl, CURLOPT_URL, url_request.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

        /* Perform the request, res will get the return code */
        res = curl_easy_perform(curl);

        /* always cleanup */
        curl_easy_cleanup(curl);
        std::cout << "response for : " << url_request << " : " << readBuffer << std::endl;
    }
}