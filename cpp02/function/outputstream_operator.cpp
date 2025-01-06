#include <iostream>

class student
{
	public:
		std::string name;
		int id;

		student(int id, std::string name)
		{
			std::cout << "Constructor called" << std::endl;
			this->id = id;
			this->name = name;
		};

		~student()
		{
			std::cout << "Destructor called" << std::endl;
		};
};

//ouput stream operator overloading
std::ostream &operator<<(std::ostream &out, const student &src)
{
	std::cout << "output operator called" << std::endl;
	out << "id: " << src.id << std::endl;
	out << "hello " << src.name;
	return out;
};

int main()
{
	student a(1, "jack");
	student b(2, "alice");
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	return 0;
}