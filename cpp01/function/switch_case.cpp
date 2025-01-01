#include <iostream>

int main(int ac, char **av)
{
	(void)ac;
	int num = atoi(av[1]);
	switch (num)
	{
		case 1:
			std::cout << "One" << std::endl;
			break;
		case 2:
			std::cout << "Two" << std::endl;
			break;
		case 3:
			std::cout << "Three" << std::endl;
			break;
		default:
			std::cout << "Unknown" << std::endl;
			break;
	}

	return 0;
}