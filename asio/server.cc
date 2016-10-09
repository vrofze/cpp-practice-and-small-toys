#include<boost/asio.hpp>
#include<thread>

using namespace boost::asio;

typedef std::shared_ptr<ip::tcp::socket> socket_ptr;

void client_session(socket_ptr sock)
{
  while(true){
    char data[512];
    std::cout << "hehe" << std::endl;
    write(*sock, buffer("ok", 2));
    /*size_t len = sock->read_some(buffer(data));
    std::cout << "len:" << len << std::endl;
    if(len > 0){
      write(*sock, buffer("ok", 2));
      }*/
  }
}

int main()
{
  io_service service;
  ip::tcp::endpoint ep(ip::tcp::v4(), 8089);
  ip::tcp::acceptor ac(service, ep);

  while(true){
    std::cout << "while true" << std::endl;
    socket_ptr psocket = std::make_shared<ip::tcp::socket>(ip::tcp::socket(service));
    ac.accept(*psocket);
    std::cout << "heha" << std::endl;
    std::thread(std::bind(client_session, psocket));
  }
}
