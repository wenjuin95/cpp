#include <iostream>

int main()
{
	{
		//pointer => point of the address that store the value
		// provide a way to access and modify variables indirectly through their memory
		// addresses and can be reassigned to point to different variables or memory
		// locations as needed
		std::string str = "hello, world!";
		std::cout << "str  : " << str << "( "<< &str << " )" << std::endl;
		std::string *str_p = NULL;//for pointer you can assing null then assign something
		str_p = &str;
		//*str_p = "cpp"; // if you can change value with pointer
		//str = "c++"; //you also can change the original value
		std::cout << "str  : " << str << "( "<< &str << " )" << std::endl;
		std::cout << "str_p: " << *str_p << "( "<< str_p << " )" << std::endl;
	}

	std::cout << std::endl;

	{
		//reference => an alias for the variable that store the value
		// when you need an alias for an existing variable and do not
		// need to change the reference itself.
		std::string str = "hello, world!";
		std::string str2 = "cpp1";
		std::cout << "str  : " << str << "( "<< &str << " )" << std::endl;
		std::string &str_r = str;
		//str_r = "cpp!"; //if you can change value with reference word without "&"
		//str = "cpp!"; //you also can change the original value
		std::cout << "str  : " << str << "( "<< &str << " )" << std::endl;
		std::cout << "str_r: " << str_r << "( "<< &str_r << " )" << std::endl;
	}
}

/**
 * POINTER :: hold memory address of the variable. need to use * to get the value
 * REFERENCE :: an alias for the variable.
 *
 * REASSIGNING
 * ===========
 * POINTER :: can be reasign
 * example: int a = 5;
 * 			int b = 10;
 * 			int *p = &a;
 * 			p = &b;
 *
 * REFERENCE :: cannot be reassign
 * example: int a = 5;
 * 			int b = 10;
 * 			int &r = a;
 * 			&r = b; //get error
 * 			r = b; //get value of "r" (is a) and change the value of a
 *
 * NULL
 * ====
 * POINTER :: can be assigned to NULL
 * REFERENCE :: cannot be assigned to NULL
 *
 * INDIRECTION
 * ===========
 * POINTER :: can have pointer to pointer
 * example: int a = 5;
 * 			int *p = &a;
 * 			int **pp = &p;
 * REFERENCE :: cannot have reference to reference
 * example: int a = 5;
 * 			int &r = a;
 * 			int &rr = r; //get error
 *
 * WHICH TO USE
 * ============
 * REFERENCE :: 1. function paramter and return type
 * 				2. when you don't need to reassign
 * POINTER   :: 1. implement data structure
 * 				2. when you need to reassign or using NULL
*/