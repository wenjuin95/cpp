#include <iostream>

int main()
{
	{
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
		// when you need an alias for an existing variable and do not
		// need to change the reference itself.
		std::string str = "hello, world!";
		std::cout << "str  : " << str << "( "<< &str << " )" << std::endl;
		std::string &str_r = str;
		//str_r = "cpp!"; //if you can change value with reference word without "&"
		//str = "cpp!"; //you also can change the original value
		std::cout << "str  : " << str << "( "<< &str << " )" << std::endl;
		std::cout << "str_r: " << str_r << "( "<< &str_r << " )" << std::endl;
	}
}