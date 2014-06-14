#include <iostream>
#include <string>

using namespace std;

class Socket {
public:
    Socket(const string& hostname) {}
};

class HttpRequest {

public:
    
    HttpRequest(const string& hostname): sock_(new Socket(hostname)) {}
    
    ~HttpRequest() {
        delete sock_;
    }
    
    void send(string soapMsg) {
        //sock_ << soapMsg;
    }
    
private:
    Socket* sock_;

};

void sendData(string soapMsg, string host) {
    HttpRequest req(host);
    req.send(soapMsg);
}


// Reduce client programmer's coding work