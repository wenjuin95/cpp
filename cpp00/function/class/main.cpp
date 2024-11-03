#include "class.hpp"

int main()
{
	student s1;

	//PRIVATE
	// s1.set_name("John");
	// s1.set_gender("male");
	// s1.set_age(20);
	// s1.display_info();

	//PUBLIC
	s1.name = "John";
	s1.gender = "male";
	s1.age = 20;
	s1.display_info();
}