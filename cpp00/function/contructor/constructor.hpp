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
 * constructor :: create an object of a class and initialize it
 * default constructor :: 1. constructor with no arguments
 *						 2. if no constructor is defined, the compiler provides 
 *							a default constructor
 *
 * destuctor :: perform cleanup tasks, 
 * 	 		   such as releasing resources or deallocating memory, 
 * 			   associated with the object before it is destroyed
 * default destructor :: 1. destructor with no arguments
 *						2. if no destructor is defined, the compiler provides 
 *						   a default destructor
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