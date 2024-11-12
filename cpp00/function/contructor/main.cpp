#include <iostream>

class student {
	private:
		std::string name;
		std::string gender;
		int age;

	public:
		student(std::string name, std::string gender, int age);
		~student();
		void set_name(std::string);
		void set_age(int);
		void set_gender(std::string);
		std::string get_name(void);
		std::string get_gender(void);
		int get_age(void);
		void display_info(void);
};


/****************************************************************************/
student::student(std::string name, std::string gender, int age) : name(name), gender(gender), age(age) {
    std::cout << "constructor called" << std::endl;
}

student::~student() {
    std::cout << "Destructor called [ " << this->name << " ]" << std::endl;
}

void student::set_name(std::string name)
{
		this->name = name;
}

void student::set_age(int age)
{
		this->age = age;
}

void student::set_gender(std::string gender)
{
		this->gender = gender;
}

std::string student::get_name(void)
{
	return this->name;
}

std::string student::get_gender(void)
{
	return this->gender;
}

int student::get_age(void)
{
	return this->age;
}

void student::display_info(void)
{
    std::cout << "Name: " << get_name() << std::endl;
    std::cout << "Gender: " << get_gender() << std::endl;
    std::cout << "Age: " << get_age() << std::endl;
}

/****************************************************************************/
int main()
{

	student s1("jane", "female", 18);
	s1.display_info();

	std::cout << std::endl;

	s1.set_name("John");
	s1.set_gender("male");
	s1.set_age(20);
	s1.display_info();
}
