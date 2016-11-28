#include <iostream>
#include <boost/asio.hpp>

using namespace boost::asio;

io_service service;

typedef boost::system::error_code error_code;

size_t read_complete(char *buff, const error_code &err, size_t bytes)
{
    if(err){
        std::cout << "read complete error" << std::endl;
        return 0;
    }

    bool found = std::find(buff, buff + bytes, '\n') < buff + bytes;

    return found ? 0 : 1;
}

void handle_connections()
{
    ip::tcp::acceptor ac(service, ip::tcp::endpoint(ip::tcp::v4(), 8089));
    char buff[1024];
    while(true){
        ip::tcp::socket sock(service);
        ac.accept(sock);
        int bytes = read(sock, buffer(buff), std::bind(read_complete, buff,
                                                       std::placeholders::_1,
                                                       std::placeholders::_2));
        std::string msg(buff, bytes);
        sock.write_some(buffer(msg));
        sock.close();
    }
}

int main()
{
    handle_connections();
    return 0;
}
