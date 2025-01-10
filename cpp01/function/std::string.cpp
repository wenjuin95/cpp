#include <iostream>

//	//std::string is a class that define a string object
//	/************************************************************************************************/
//  /* purpose of using "std::string" because you can straight malloc and modify instead			*/
//	/* using "char *" malloc then modify															*/
//	/*																								*/
//	/* 1. Ease of Use: No need to manage null terminators or worry about buffer overflows.          */
//	/*                                                                                              */
//	/* 2. Memory Management: handles memory allocation and deallocation automatically,              */
//	/*    reducing the risk of memory leaks and buffer overflows.                                   */
//	/*                    													  						*/
//	/* 3. Functionality: comes with a rich set of member functions for various string  	            */
//	/*    operations, such as finding substrings, replacing parts of the string, and more.     		*/
//	/* 					                                                                      		*/
//	/* 4. Safety: safer to use because it manages its own memory and reduces the		            */
//	/*    chances of common errors associated with raw character arrays.							*/
//	/************************************************************************************************/
//	//to visualize std::string handle memory by "new" it so that the string can be stored in the heap to visualize
//	int main()
//	{
//		std::string *str = new std::string("Hello");
//		std::cout << *str << std::endl;
//		//delete str; //is to free the memory allocated by the new operator
//	}

///////////////////////////////////////////////////////////////////////////////////////////////////////
#include <cstring>

int main()
{
	//memory allocate for modify
	std::string str = "Hello";
	str += " World";
	std::cout << "str: " << str << std::endl;

	//memory allocate for modify
	char *str2 = new char[10];
	strcpy(str2, "Hello");
	strcat(str2, " World");
	std::cout << "str2: " << str2 << std::endl;
	delete [] str2;
	//const char *str2 = "Hello";
	//std::cout << "str2: " << str2 << std::endl;
}