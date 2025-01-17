#include <iostream>

/**
 * namespace: useful when you have two function with same name but different functionality
 * note: 1. namespace is used to avoid name conflict
 *       2. mostly use for "std" namespace for predefined functions
 *          EXAMPLE: before namespace -> std::cout, std::cin
 *                  after namespace -> cout, cin
 *
*/

//using namespace std; //remove the "std::" from cout and cin //sample 3

namespace say_hello //sample 1
{
    void msg(void)
    {
        std::cout << "Hello" << std::endl;
    }
}

namespace say_goodbye //sample 2
{
    void msg(void)
    {
        std::cout << "Goodbye" << std::endl;
    }
}


using namespace say_hello; //sample 1
int main()
{
    msg(); //sample 1
	//say_goodbye::msg(); //sample 2
    std::cout << "say something without \"std\"" << endl; //sample 3
    return 0;
}