#include <iostream>

int main(int ac, char **av)
{
    (void)ac;
    std::string s1 = av[1];

    size_t pos = s1.find(av[2], 3);

    std::cout << pos << std::endl;
}