#include <iostream>

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "Error!!!\nusage: ./a.out [string] [pos_to_start] [len_of_string]" << std::endl;
		return 1;
	}
	std::string res;
    std::string s1 = av[1];
	int pos_to_start = atoi(av[2]);
	int len_of_string = atoi(av[3]);
	if (len_of_string == 0)
		res = s1.substr(pos_to_start);
	else
    	res = s1.substr(pos_to_start, len_of_string);
    std::cout << res << std::endl;
}