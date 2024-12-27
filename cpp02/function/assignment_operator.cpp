#include <iostream>

class student
{
	private:
	public:
		int id;
		std::string name;
		student(){
			std::cout << "Default constructor" << std::endl;
		};

		student(int id, std::string name)
		{
			this->id = id;
			this->name = name;
			std::cout << "Constructor" << std::endl;
		};

		student &operator=(const student &src)
		{
			std::cout << "Copy assignment operator" << std::endl;
			this->id = src.id + 1;
			this->name = src.name + "1";
			return (*this);
		};

};

int main()
{
	student a(1, "jack");
	student b(2, "alice");
	student c;
	c = a = b;
	std::cout << c.name << std::endl;
	return 0;
}