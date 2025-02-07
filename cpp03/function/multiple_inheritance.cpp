#include <iostream>
#include <string>

/**
 * multiple inheritance :: class can inherit from more than one class
*/

//EXAMPLE:
//class A
//{
//	public:
//		A()
//		{
//			std::cout << "A constructor" << std::endl;
//		}
//};

//class B
//{
//	public:
//		B()
//		{
//			std::cout << "B constructor" << std::endl;
//		}
//};

//class C : public A, public B
//{
//	public:
//		C()
//		{
//			std::cout << "C constructor" << std::endl;
//		}
//};

//int main()
//{
//	C c;
//	return 0;
//}

/********************************************************************************************************/

/**
 * diamond problem :: when a class inherits from two classes that have a common base class
 *
 * EXAMPLE:
 *        A
 *       ===
 *       name
 *       / \
 *      B   C
 *       \ /
 *        D
 *    D has two copies of name
 * this cause ambiguity
*/

//EXAMPLE
//class A
//{
//	public:
//	    A(int x)  { std::cout << "A::A called" << std::endl;   }
//};

//class B : public A
//{
//	public:
//	    B(int x) : A(x)
//		{
//	       std::cout<<"B::B called"<< std::endl;
//	    }
//};

//class C : public A
//{
//	public:
//	    C(int x) : A(x)
//		{
//	        std::cout<<"C::C called"<< std::endl;
//	    }
//};

//class D : public B, public C
//{
//	public:
//	    D(int x):C(x), B(x)
//		{
//	        std::cout<<"D::D called"<< std::endl;
//	    }
//};

//int main()
//{
//    D d(30);
//}

/**
 * 1. "A" called 2 time.
 * 2. "D" will have two copies of "A".
 * 3. this cause ambiguities
 * 4. to solve this we use "virtual", class "B" and "C" as virtual base
 *    to avoid two copies of "A"
*/
/********************************************************************************************************/
class A
{
	public:
	    A(int x)  { std::cout << "A::A called" << std::endl;   }
		A() { std::cout << "A::A default called" << std::endl; }
};

class B : virtual public A
{
	public:
	    B(int x) : A(x)
		{
	       std::cout<<"B::B called"<< std::endl;
	    }
};

class C : virtual public A
{
	public:
	    C(int x) : A(x)
		{
	        std::cout<<"C::C called"<< std::endl;
	    }
};

class D : public B, public C
{
	public:
	    D(int x):C(x), B(x)
		{
	        std::cout<<"D::D called"<< std::endl;
	    }
};

int main()
{
    D d(30);
}

/**
 * when use "virtual", default constructor of granparent class
 * is called by default even if the parent classes explicitly call constructor
*/
/********************************************************************************************************/