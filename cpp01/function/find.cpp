#include <iostream>

int main(int ac, char **av)
{
    if (ac != 3)
	{
		std::cout << "Error!!!\nusage: ./a.out [string] [string]" << std::endl;
		exit(1);
	}
    std::string s1 = av[1];

	//first param: string to find
	//second param: position to start
    size_t pos = s1.find(av[2], 0);

	//npos: mean end of string
	if (pos == std::string::npos)
		std::cout << "Not found" << std::endl;
	else
    	std::cout << pos << std::endl;
}