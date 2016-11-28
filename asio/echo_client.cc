#include <iostream>
#include <boost/thread/thread.hpp>
#include <boost/asio.hpp>

using namespace boost::asio;

typedef boost::system::error_code error_code;
io_service service;
ip::tcp::endpoint ep(ip::address::from_string("127.0.0.1"), 8089);

size_t read_complete(char *buf, const error_code &err, size_t bytes)
{
    if(err){
        std::cout << "read_complete" << std::endl;
        return 0;
    }
    bool found = std::find(buf, buf + bytes, '\n') < buf + bytes;
    return found ? 0 : 1;
}

void sync_echo(std::string msg)
{
    msg += '\n';
    ip::tcp::socket sock(service);
    sock.connect(ep);
    sock.write_some(buffer(msg));
    char buf[1024];
    int bytes = read(sock, buffer(buf), std::bind(read_complete, buf,
                                                    std::placeholders::_1,
                                                    std::placeholders::_2));
    std::string copy(buf, bytes - 1);
    msg = msg.substr(0, msg.size() - 1);
    std::cout << "server echoed our" << msg << ": "
              << (copy == msg ? "OK" : "FAIL") << std::endl;
    sock.close();
}

int main()
{
    char *messages[] = {"forst says hi", "vrofze just got home",
                        "so as wang", "Boost.Asio is fun", 0 };
    boost::thread_group threads;
    for(char **message = messages; *message; ++message){
        threads.create_thread(std::bind(sync_echo, *message));
        boost::this_thread::sleep(boost::posix_time::millisec(100));
    }
    threads.join_all();

    return 0;
}
