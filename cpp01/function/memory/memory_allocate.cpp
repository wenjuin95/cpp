#include <iostream>
#include <string>

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

/******************************************************************************************* */

//memory management for object
class Student {
    public:
        std::string name;
        int age;
};

int main()
{
    Student *s = new Student[2];
    
    s[0].name = "John";
    s[0].age = 20;
    s[1].name = "Jane";
    s[1].age = 22;

    for (int i = 0; i < 2; i++)
    {
        std::cout << "Name: " << s[i].name << std::endl
                    << " Age: " << s[i].age << std::endl;
    }

    delete []s;
    return 0;
}