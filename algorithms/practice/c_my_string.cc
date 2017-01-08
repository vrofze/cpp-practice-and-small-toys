#include <cstring>
#include <iostream>

class CMyString
{
public:
    CMyString(char *p_data = nullptr)
        {
            this->p_data = new char[strlen(p_data) + 1];
            strcpy(this->p_data, p_data);
        }
    CMyString(const CMyString& str)
        {
            this->p_data = new char[strlen(str.p_data) + 1];
            strcpy(this->p_data, str.p_data);
        }
    ~CMyString()
        {
            delete[] p_data;
        }

    CMyString& operator=(const CMyString &str);

private:
    char *p_data;
};

CMyString& CMyString::operator=(const CMyString &str)
{
    if(this == &str){
        return *this;
    }

    delete[] p_data;
    p_data = nullptr;
    p_data = new char[strlen(str.p_data) + 1]; // end '\0'
    strcpy(p_data, str.p_data);
    std::cout << p_data << std::endl;

    return *this;
}

int main()
{
    char p[10] = "hello";
    CMyString str(p);
    CMyString str2 = str;
    str2 = str;
    return 0;
}
