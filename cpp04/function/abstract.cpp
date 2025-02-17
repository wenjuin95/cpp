#include <iostream>

/**
 * 1. abstract class serves as a blueprint for other classes (derived classes) to implement.
 * 2. It is a class that cannot be instantiated on its own and is designed to be inherited by other classes.
 * 3. abstract class is a class that has at least one pure virtual function.
 * 4. pure virtual function means that the function has no implementation.
*/

class Base
{
    private:
    	int x;

	public:
	    //this is pure virtual function
	    virtual void fun() = 0;

	    // getter function to access x
	    int getX() { return x; }
};

// This class inherits from Base and implements fun()
class Derived : public Base
{
	private:
    	int y;
	public:
	    // implementation of the pure virtual function
	    void fun() { std::cout << "fun() called"; }
};

int main(void)
{
	// {
	// 	// creating an object of Base class
	// 	Base b; // Error: cannot instantiate an abstract class
	// 	b.fun();
	// }

	{
		// creating an object of Derived class
		Derived d;
		// calling the fun() function of Derived class
		d.fun();
	}


    return 0;
}
/************************************************************************************************************/

/**
 * if you not implement the pure virtual function in the derived class, the derived class will also become an abstract class.
*/

// class Base
// {
// 	private:
// 		int x;
// 	public:
// 		virtual void fun() = 0;
// 		int getX() { return x; }
// };

// class Derived : public Base
// {
//     private:
//     	int y;
// };

// int main()
// {
// 	Derived d;
// 	d.fun(); // Error: pure virtual function called
// }
