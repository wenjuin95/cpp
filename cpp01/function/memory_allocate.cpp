#include <iostream>
#include <string>

//syntax for memory allocation
// <new> <data_type>;
// new : keyword to allocate memory
// data_type : data type of the variable

//syntax for memory allocation with initialization
// <new> <data_type> (<value>);
// new : keyword to allocate memory
// data_type : data type of the variable
// value : value to be initialized

//syntax for memory deallocation for array
//new [] <data_type>;
// new : keyword to allocate memory
// [] : allocate memory for array
// data_type : data type of the variable

/********************************************************************************************/

//<delete> <data_type>;
// delete : keyword to deallocate memory
// data_type : data type of the variable

//delete [] <data_type>;
// delete : keyword to deallocate memory
// [] : deallocate memory for array
// data_type : data type of the variable

/********************************************************************************************/

//memory allocation
int main()
{
	std::string *str = new std::string("Hello World");
	std::cout << *str << std::endl;
	delete str;
}

/********************************************************************************************/

//memory allocation with array
// int main()
// {
//     char *str;

//     str = new char[10]; // memory allocation like malloc
//     str[0]= 'a';
//     str[1] = 'b';
//     str[2] = 'c';
//     str[3] = '\0';
//     std::cout << str << std::endl;
//     delete [] str; // memory deallocation like free
//     return 0;
// }

/********************************************************************************************/

//memory management for object
//class Student {
//    public:
//        std::string name;
//        int age;
//};

//int main()
//{
//    Student *s = new Student[2];

//    s[0].name = "John";
//    s[0].age = 20;
//    s[1].name = "Jane";
//    s[1].age = 22;

//    for (int i = 0; i < 2; i++)
//    {
//        std::cout << "Name: " << s[i].name << std::endl
//                    << " Age: " << s[i].age << std::endl;
//    }

//    delete []s;
//    return 0;
//}