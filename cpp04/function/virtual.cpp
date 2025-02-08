#include <iostream>
#include <string>

/**
 * virtual function : a function that can be redefined in a derived class
 *
 * RULE:
 * 1. cannot be static
 * 2. should be accessed using a pointer or refence of base class type to achieve
 *    runtime polymorphism
 * 3. prototype of virtual function should be the same in the base as well as the derived class
 * 4. class may have a vertual destructor but it cannot have a virtual constructor
*/

class A
{
	public:
		void print(void)const
		{
			std::cout << "print A" << std::endl;
		}

		void show(void)const
		{
			std::cout << "show A" << std::endl;
		}
};

class B : public A
{
	public:
		void print(void)const
		{
			std::cout << "print B" << std::endl;
		}

		void show(void)const
		{
			std::cout << "show B" << std::endl;
		}
};

int main()
{
	A *a;
	B b;
	a = &b;

	a->print();
	a->show();
}
/**********************************************************************************************/

/**
 * virtual destructor : delete the object of the derived class using a pointer of the base class
 *
*/

// using namespace std;

// class base {
//   public:
//     base()
//     	{ cout << "base constuctor\n"; }
//     ~base()
//     	{ cout<< "base destructor\n"; }
// };

// class derived: public base {
//   public:
//     derived()
// 		{ cout << "derived constructor\n"; }
//     ~derived()
//     	{ cout << "derived destructor\n"; }
// };

// int main()
// {
//   base *b = new derived();
//   delete b;
// }