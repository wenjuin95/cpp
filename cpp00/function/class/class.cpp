#include "class.hpp"

/*****************************************************************************/
/*                            PRIVATE                                        */

// void student::set_name(std::string name) { this->name = name; }

// void student::set_age(int age) { this->age = age; }

// void student::set_gender(std::string gender) { this->gender = gender; }

// std::string student::get_name(void) { return this->name; }
// std::string student::get_gender(void) { return this->gender; }
// int student::get_age(void) { return this->age; }

// void student::display_info(void)
// {
//     std::cout << "Name: " << get_name() << std::endl;
//     std::cout << "Gender: " << get_gender() << std::endl;
//     std::cout << "Age: " << get_age() << std::endl;
// }

/*****************************************************************************/
/*                            PUBLIC                                         */

void student::display_info(void)
{
    std::cout << "Name: " << this->name << std::endl;
    std::cout << "Gender: " << this->gender << std::endl;
    std::cout << "Age: " << this->age << std::endl;
}