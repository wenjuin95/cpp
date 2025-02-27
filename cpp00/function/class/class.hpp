#ifndef CLASS_HPP
#define CLASS_HPP
#include <iostream>

/**
 * private: help us to hide the data from the outside class
 * EXAMPLE: you can't access the variable in the class from the outside file and you can't change the value of the variable in the class from the outside file
 * method for accessing the private variable: use "set" and "get" method
 * 
 * 1. set method: used to set the value of the private variable
 * SYNTAX: <void> set_<variable_name>(<data_type> <parameter_name>) { <class_name> = <parameter_name>; }
 * EXAMPLE: void set_name(std::string name) { this->_name = name; }
 * 
 * 2. get method: used to get the value of the private variable
 * SYNTAX: <data_type> get_<variable_name>(void) { return <class_name>; }
 * EXAMPLE: std::string get_name(void) { return this->_name; }
 */
// class student { //with private
// 	private:
// 		std::string _name;
// 		std::string gender;
// 		int age;

// 	public:
// 		void set_name(std::string);
// 		void set_age(int);
// 		void set_gender(std::string);
// 		std::string get_name(void);
// 		std::string get_gender(void);
// 		int get_age(void);
// 		void display_info(void);
// };

class student { //public
	public:
		std::string name;
		std::string gender;
		int age;
		void display_info(void);
};

#endif