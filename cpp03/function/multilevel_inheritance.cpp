#include <iostream>

/**
 * multi-lelvel inheritance : A derived class is created from another derived class.
 */

class A
{
	public:
	    A(int x)  { std::cout << "A::A called" << std::endl;   }
};

class B : public A
{
	public:
	    B(int x) : A(x)
		{
	       std::cout<<"B::B called"<< std::endl;
	    }
};

class C : public B
{
	public:
	    C(int x) : B(x)
		{
	        std::cout<<"C::C called"<< std::endl;
	    }
};

class D : public C
{
	public:
	    D(int x):C(x)
		{
	        std::cout<<"D::D called"<< std::endl;
	    }
};

int main()
{
    D d(30);
}