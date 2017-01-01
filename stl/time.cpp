#include <ctime>
#include <iostream>

class Test{
public:
    static const int test() { return 10;}
};

int main()
{
    time_t raw_time = time(nullptr);
    if(raw_time == -1){
        return 0;
    }

    std::cout << "now is:" << raw_time << std::endl;
    std::cout << "now is:" << ctime(&raw_time) << std::endl;

    tm *timeinfo;
    timeinfo = localtime(&raw_time);
    std::cout << "now is:" << asctime(timeinfo) << std::endl;

    std::cout << "year:" << timeinfo->tm_year << std::endl;
    std::cout << "month:" << timeinfo->tm_mon << std::endl;
    std::cout << "day:" << timeinfo->tm_mday << std::endl;

    char buff[256] = {0};
    strftime(buff, sizeof(buff) / sizeof(buff[0]), "today is %Ynian%myue%dri", timeinfo);
    std::cout << buff << std::endl;

    std::cout << Test::test() << std::endl;

    return 0;
}
