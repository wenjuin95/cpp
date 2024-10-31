#include "constructor.hpp"

int main()
{

	student s1("jane", "female", 18);
	s1.display_info();
	std::cout << std::endl;
	s1.set_name("John");
	s1.set_gender("male");
	s1.set_age(20);
	s1.display_info();
}