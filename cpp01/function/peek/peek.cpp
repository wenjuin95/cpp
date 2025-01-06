#include <iostream>
#include <sstream>
#include <fstream>

//use input string
int main(int ac, char **av)
{
	(void)ac;
	std::istringstream str(av[1]);

	//peek: check next character in input stream without extracting it
	//std::istringstream::traits_type::eof(): check if the file is empty
	if (str.peek() == std::istringstream::traits_type::eof())
		std::cout << "The input string is empty" << std::endl;
	else
		std::cout << str.str() << std::endl;
}

////////////////////////////////////////////////////////////////////////////////////

//// use text file
//int main(void)
//{
//	std::ifstream file("test.txt");

//	//peek: check next character in input stream without extracting it
//	//std::ifstream::traits_type::eof(): check if the file is empty
//	if (file.peek() == std::ifstream::traits_type::eof())
//		std::cout << "The input file is empty" << std::endl;
//	else
//		std::cout << "The input file is not empty" << std::endl;
//}