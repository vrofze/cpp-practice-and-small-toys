#include <boost/asio.hpp>
#include <boost/system/error_code.hpp>

using namespace boost::asio;

typedef std::shared_ptr<ip::tcp::socket> socket_ptr;
io_service service;
ip::tcp::endpoint ep(ip::tcp::v4(), 8089);
ip::tcp::acceptor ac(service, ep);

void handle_accept(socket_ptr, const boost::system::error_code&);

void start_accept(socket_ptr sock)
{
    ac.async_accept(*sock, std::bind(handle_accept, sock, std::placeholders::_1));
}

void handle_accept(socket_ptr psock, const boost::system::error_code &err)
{
    std::cout << "handle accept" << std::endl;
    if(err){
        std::cout << "error" << std::endl;
        return;
    }
    socket_ptr sock(new ip::tcp::socket(service));
    start_accept(sock);
}

int main()
{
    socket_ptr sock(new ip::tcp::socket(service));
    start_accept(sock);
    service.run();
    return 0;
}
