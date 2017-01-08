#include <iostream>
#include <climits>

int StrToInt(char *pstr)
{
    if(pstr == nullptr){
        throw "str is null";
    }

    char *p = pstr;
    bool is_minus = false;

    if(*p == '+'){
        ++p;
    }
    if(*p == '-'){
        is_minus = true;
        ++p;
    }

    long result = 0;
    while(*p != 0){  // ascii 0
        if(*p >= '0' && *p <= '9'){
            result = result * 10 + (*p - '0');

            if((result > INT_MAX && !is_minus) || (-result < INT_MIN && is_minus)){
                throw "out of index bound";
                return 0;
            }

            ++p;
        }
        else {
            throw "error char";
            return 0;
        }
    }

    if(is_minus){
        result = 0 - result;
    }

    return static_cast<int>(result);
}


int main()
{
    std::cout << "input the int:";
    char *str = new char[30];
    std::cin >> str;
    std::cout << str << std::endl;

    int result = StrToInt(str);

    std::cout << "result:" << result << std::endl;

    return 0;
}
