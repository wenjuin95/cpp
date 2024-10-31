#include "class.hpp"

void student::set_name(std::string name) 
{
	if (name == "")
	{
		std::cerr << "Name cannot be empty" << std::endl;
		return;
	}
	else
		this->name = name;
}

void student::set_age(int age)
{
	if (age < 0)
	{
		std::cerr << "Age cannot be negative" << std::endl;
		return;
	}
	else
		this->age = age;
}

void student::set_gender(std::string gender) 
{
	if (gender == "male" || gender == "female")
		this->gender = gender; 
	else
	{
		std::cerr << "only male or famale are allowed" << std::endl;
		return;
	}
}

std::string student::get_name(void) { return this->name; }
std::string student::get_gender(void) { return this->gender; }
int student::get_age(void) { return this->age; }

void student::display_info(void)
{
    if (name == "" || age < 0 || (gender != "male" && gender != "female"))
        return;

    std::cout << "Name: " << get_name() << std::endl;
    std::cout << "Gender: " << get_gender() << std::endl;
    std::cout << "Age: " << get_age() << std::endl;
}