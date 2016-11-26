#include<boost/asio.hpp>

using namespace boost::asio;

int main(int argc, char * argv[])
{
  // dell with input
  if(argc < 2){
    std::cout << "please input a url" << std::endl;
    return 0;
  }
  std::string url = argv[1];

  io_service service;
  ip::tcp::resolver resolver(service);
  ip::tcp::resolver::query query(url, "80");
  ip::tcp::resolver::iterator iter = resolver.resolve(query);
  ip::tcp::resolver::iterator end; // as a end point
  for(; iter != end; ++iter){
    ip::tcp::endpoint ep = *iter;
    std::cout << ep.address().to_string() << std::endl;
  }
  return 0;
}
