#include<boost/asio.hpp>

using namespace boost::asio;

void connect_handler(const boost::system::error_code& ec)
{

}

int main()
{
  io_service service;
  ip::tcp::endpoint ep(ip::address::from_string("127.0.0.1"), 8089);
  ip::tcp::socket sock(service);
  sock.async_connect(ep, connect_handler);
  service.run();
}
