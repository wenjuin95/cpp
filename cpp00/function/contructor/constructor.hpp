#ifndef CONSTRUCTOR_HPP
#define CONSTRUCTOR_HPP

#include <iostream>

/**
 * constructor: function that create a class object when main function is called
 * EXAMPLE: when main function is called, it will create a student and initialize name, gender and age
 * 
 * destructor: function that destroy a class object after main function is executed
 * EXAMPLE: when main function is executed, it will destroy the student object (if you have memory allocation, it will deallocate the memory)
 *  
*/
class student {
	private:
		std::string name;
		std::string gender;
		int age;

	public:
		student(std::string name, std::string gender, int age);
		~student();
		void set_name(std::string);
		void set_age(int);
		void set_gender(std::string);
		std::string get_name(void);
		std::string get_gender(void);
		int get_age(void);
		void display_info(void);
};

#endif