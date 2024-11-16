#include <iostream>

int main()
{
    std::string s1 = "hello, my name is john";
    std::string res = s1.substr(7, 2); //postion: 7, get 2 characters
    std::cout << res << std::endl;
}