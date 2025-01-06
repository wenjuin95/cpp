#include <iostream>

// class Student {
// public:
//     std::string name;
//     int id;

//     // Constructor
//     Student(const std::string &name, int id) : name(name), id(id) {
//         std::cout << "Student constructor called" << std::endl;
//     }

//     // Copy constructor
//     Student(const Student &other) : name(other.name), id(other.id) {
//         std::cout << "Student copy constructor called" << std::endl;
//     }
// };

// //if you remove & from the Student parameter, it will call the copy constructor
// void print_student(Student &student) {
//     std::cout << student.name << " " << student.id << std::endl;
// }

// int main() {
//     Student student("John Doe", 123);
//     print_student(student);
//     return 0;
// }

//////////////////////////////////////////////////////////////////////////////////////////////////////

class Student
{
	public:
	    std::string name;
	    int id;

	    // Constructor
	    Student(const std::string &name, int id) : name(name), id(id)
		{
	        std::cout << "Student constructor called" << std::endl;
	    }

	    // Copy constructor
	    Student(const Student &other) : name(other.name), id(other.id)
		{
	        std::cout << "Student copy constructor called" << std::endl;
	    }

	    // Getter for name (by reference)
	    std::string &getName(void)
		{
	        return this->name;
	    }
};

void print_student(Student &student)
{
    std::cout << student.getName() << " " << student.id << std::endl;
}

// Function to modify student name by reference (will not compile)
void modify_student_name(Student &student)
{
    // This will not compile because getNameByRef returns a const reference
 	std::string &name = student.getName();
    name = "Jane Doe";
    std::cout << "Modified name (by value): " << name << std::endl;
}

int main() {
    Student student("John Doe", 123);

    std::cout << "Using getNameByRef:" << std::endl;
    print_student(student);

	std::cout << std::endl;

    std::cout << "Attempting to modify name by value:" << std::endl;
	modify_student_name(student);

	std::cout << std::endl;

	print_student(student); // Verify that the original name is unchanged
    return 0;
}
