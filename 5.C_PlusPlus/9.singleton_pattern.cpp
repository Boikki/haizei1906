/*************************************************************************
	> File Name: 9.singleton_pattern.cpp
	> Author: rEn Chong 
	> Mail: renboyu@hrbeu.edu.cn 
	> Created Time: Tue Apr 19 13:44:30 2022
 ************************************************************************/

#include <iostream>
#include <mutex>
using std::cin;
using std::cout;
using std::endl;

class HttpServer {
public :
    static HttpServer *getInstance() {
        std::unique_lock<std::mutex> lock(m_mutex);
        if (instance == nullptr) {
            instance = new HttpServer();
        }
        return instance;
    }

private :
    static HttpServer *instance;
    static std::mutex m_mutex;
    HttpServer() {}
    HttpServer(const HttpServer &) = delete;
    ~HttpServer() {}
};
HttpServer *HttpServer::instance = nullptr;
std::mutex m_mutex;
int main() {
    HttpServer *t1 = HttpServer::getInstance();
    HttpServer *t2 = HttpServer::getInstance();
    cout << t1 << "\t" << t2 << endl;
    return 0;
}
