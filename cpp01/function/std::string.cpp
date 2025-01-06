#include <iostream>

//int main()
//{
//	//std::string is a class that define a string object
//	/************************************************************************************************/
//	/* 1. Ease of Use: easier-to-use interface for string manipulation. You can easily concatenate, */
//	/*    compare, and perform other operations on strings                                          */
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
//	std::string *str = new std::string("Hello");
//	std::cout << *str << std::endl;
//	//delete str; //is to free the memory allocated by the new operator
//}

///////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
	std::string str = "Hello";
	std::cout << str << std::endl;
}