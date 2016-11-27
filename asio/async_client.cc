#include <iostream>
#include <boost/asio.hpp>

using namespace boost::asio;

class Client
{
public:
    typedef std::shared_ptr<ip::tcp::socket> socket_ptr;
    Client(io_service &ser): service(ser),
                             ep(ip::address::from_string("127.0.0.1"), 8089)
        { }

    void start()
        {
            socket_ptr psocket = std::make_shared<ip::tcp::socket>(ip::tcp::socket(service));
            start_connect(psocket);
            service.run();
        }

private:
    io_service &service;
    ip::tcp::endpoint ep;

    void start_connect(socket_ptr psocket)
        {
            /*
            psocket->connect(ep);
            char *buff = new char[512];
            psocket->async_receive(buffer(buff, 512),
                                   std::bind(&Client::read_handler, this, buff,
                                             std::placeholders::_1,
                                             std::placeholders::_2));
            */
            psocket->async_connect(ep, std::bind(&Client::handle_connect,
                                                 this, psocket,
                                                 std::placeholders::_1));
        }
    void handle_connect(socket_ptr psocket, const boost::system::error_code ec)
        {
            if(ec){
                std::cout << "error" << std::endl;
                return;
            }
            // std::string str;
            char str[512] = "";
            boost::system::error_code error;
            psocket->read_some(buffer(str, 512), error);
            std::cout << "receive:" << str << std::endl;

            std::cout << "send:";
            std::cin.getline(str, 512);
            psocket->write_some(buffer(str), error);
            socket_ptr psock = std::make_shared<ip::tcp::socket>(ip::tcp::socket(service));
            this->start_connect(psock);
        }
    };

int main()
{
    io_service service;
    Client client(service);
    client.start();

    return 0;
}
