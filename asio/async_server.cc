#include<boost/asio.hpp>

using namespace boost::asio;

class Server
{
public:
  typedef std::shared_ptr<ip::tcp::socket> socket_ptr;
  Server(io_service &ser):
    service(ser), ep(ip::tcp::v4(), 8089), ac(service, ep) { }
  void start()
  {
    socket_ptr psocket = std::make_shared<ip::tcp::socket>(ip::tcp::socket(service));
    start_accept(psocket);
  }
protected:
  io_service &service;
  ip::tcp::endpoint ep;
  ip::tcp::acceptor ac;

  void start_accept(socket_ptr psocket)
  {
    ac.async_accept(*psocket, std::bind(this->handle_accept, psocket, std::placeholders::_1));
  }

  void handle_accept(socket_ptr psocket, const boost::system::error_code ec)
  {
    if(ec)
      return;
    *psocket.async_write_some();
    socket_ptr psock = std::make_shared<ip::tcp::socket>(ip::tcp::socket(service));
    this->start_accept(psock);
  }
};


int main()
{
  io_service service;
  Server server(service);
  server.start();
}
