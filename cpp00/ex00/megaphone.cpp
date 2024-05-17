#include <iostream>

int main(int ac, char **av)
{
	int i;
	int j;

	if (ac != 1)
	{	
		i = 1;
		while (av[i])
		{
			j = 0;
			while (av[i][j])
			{
				if (av[i][j] >= 'a' && av[i][j] <= 'z')
					av[i][j] = av[i][j] - 32;
				std::cout << av[i][j];
				j++;
			}
			i++;
		}
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
}