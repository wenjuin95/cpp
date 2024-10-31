#ifndef CLASS_HPP
#define CLASS_HPP
#include <iostream>

/**
 * private: help us to hide the data from the outside world
 * EXAMPLE: you can't access the variable in the class from the outside file and you can't change the value of the variable in the class from the outside file
 * method for accessing the private variable: use "set" and "get" method
 * 1. set method: used to set the value of the private variable
 * 2. get method: used to get the value of the private variable
 */
class student {
	private:
		std::string name = "low";
		std::string gender = "male";
		int age = 20;

	public:
		void set_name(std::string);
		void set_age(int);
		void set_gender(std::string);
		std::string get_name(void);
		std::string get_gender(void);
		int get_age(void);
		void display_info(void);
};

#endif