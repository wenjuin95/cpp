#include <iostream>

/****************************************************************************************/
//shallow copy
class Demo
{
	private:
		int data, data2;
	public:
		void display()
		{
			std::cout << "Data: " << data << std::endl;
			std::cout << "Data2: " << data2 << std::endl;
		}

		void set_value(int a, int b)
		{
			data = a;
			data2 = b;
		}
};

int main()
{
	Demo obj1;
	obj1.set_value(10, 20);
	obj1.display();

	Demo obj2 = obj1; // this called shallow copy
	obj2.display();

	return 0;
}
/**
 * Shallow copy: The default copy constructor provided by the compiler
*/

/****************************************************************************************/
// //deep copy
// class Demo
// {
// 	private:
// 		int data, data2, *p;
// 	public:
// 		Demo()
// 		{
// 			p = new int;
// 		}

// 		//this will be called deep copy
// 		Demo(const Demo &b)
// 		{
// 			data = b.data;
// 			data2 = b.data2;
// 			p = new int;
// 			*p = *b.p;
// 		}

// 		Demo &operator=(const Demo &b)
// 		{
// 			data = b.data;
// 			data2 = b.data2;
// 			if (p != NULL) //put this to avoid memory leak because if you re-copy the object it will create a new memory and the old memory will not be deleted
// 				delete p;
// 			p = new int(*b.p);
// 			return *this;
// 		}

// 		//when finish the object must delete the pointer
// 		~Demo()
// 		{
// 			delete p;
// 		}

// 		void display()
// 		{
// 			//if you don't open deep copy the pointer just point the original and it didn't copy
// 			std::cout << "Data: " << data << std::endl;
// 			std::cout << "Data2: " << data2 << std::endl;
// 			std::cout << "Pointer: " << *p << " (" << p << ") " << std::endl;
// 		}

// 		void set_value(int a, int b, int c)
// 		{
// 			data = a;
// 			data2 = b;
// 			*p = c;
// 		}
// };

// int main()
// {
// 	Demo obj1;
// 	obj1.set_value(10, 20, 30);
// 	std::cout << "object 1" << std::endl;
// 	obj1.display();

// 	Demo obj2 = obj1; // this called shallow copy
// 	std::cout << "object 2" << std::endl;
// 	obj2.display();

// 	obj1.set_value(100, 200, 300);
// 	std::cout << std::endl << "object 1 changed" << std::endl;
// 	obj1.display();
// 	std::cout << "object 2" << std::endl;
// 	obj2.display();

// 	obj2 = obj1;
// 	std::cout << std::endl << "object 1 changed" << std::endl;
// 	obj1.display();
// 	std::cout << "object 2 changed" << std::endl;
// 	obj2.display();

// 	return 0;
// }
