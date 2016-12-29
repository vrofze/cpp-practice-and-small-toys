#include <iostream>
#include <string>
#include <cstring>

class Solution {
public:
    void replaceSpace(char *str,int length) {
        if(str == 0 && length <= 0)
            return;

        int str_len = 0; // str length
        int count = 0;  // space count
        while(str[str_len] != '\0'){
            if(str[str_len] == ' ')
                ++count;
            ++str_len;
        }
        std::cout << str_len << " " << count << std::endl;
        str_len = str_len - 1; // '\0'

        int new_len = str_len + count * 2; // new str length
        std::cout << new_len << std::endl;
        if(new_len > length)
            return;
        int str_index = str_len;
        int new_index = new_len;
        while(str_index >= 0){
            if(str[str_index] == ' '){
                str[new_index--] = '0';
                str[new_index--] = '2';
                str[new_index--] = '%';
            }
            else{
                str[new_index--] = str[str_index];
            }
            --str_index;
        }
    }
};

int main()
{
    Solution sol;
    std::string stri = "Hellow world and my name is frost";
    char *str = new char[40];
    strcpy(str, stri.c_str());
    sol.replaceSpace(str, 16);
    for(int j = 0; j < 40; ++j)
        std::cout << str[j];


    return 0;
}
