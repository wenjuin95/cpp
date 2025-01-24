#include <iostream>
#include <string>

class Person
{
	public:
		std::string name;
		void eat(std::string food)
		{
			std::cout << name << " eats " << food << std::endl;
		}
};

int main()
{
	Person john;
	john.name = "john";
	john.eat("apple");
}