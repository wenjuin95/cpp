#include <iostream>

//INHERITANCE
//Inheritance is a feature of object-oriented programming that allows code reusability when a class includes properties and methods of another class.

//SYNTAX
/**
 * class DerivedClass : accessSpecifier BaseClass
 * {
 *		DerivedClass class body
 * };
 *
 * DerivedClass: name of the new class, which will inherit the base class
 * accessSpecifier: specify the access mode
 * BaseClass: name of the base class
*/

/**
 * without inheritance
*/
class Menu
{
	public:
		std::string name;
		int price;
};

class Drink
{
	public:
		std::string name;
		int price;
		bool hot;
};

int main()
{
	Menu menu;
	Drink drink;

	menu.name = "Hamburger";
	menu.price = 1000;

	drink.name = "Coke";
	drink.price = 500;
	drink.hot = true;

	std::cout << "Menu: " << menu.name << " Price: " << menu.price << std::endl;
	std::cout << "Drink: " << drink.name << " Price: " << drink.price << " (Hot: " << (drink.hot ? "yes": "no") << ")" << std::endl;
}

////////////////////////////////////////////////////////////////////////////////////////////

/**
 * with inheritance you can save from writing the same code over and over again
*/
//class Menu
//{
//	public:
//		std::string name;
//		int price;
//};

//class Drink : public Menu
//{
//	public:
//		bool hot;
//};

//int main()
//{
//	Menu menu;
//	Drink drink;

//	menu.name = "Hamburger";
//	menu.price = 1000;

//	drink.name = "Coke";
//	drink.price = 500;
//	drink.hot = true;

//	std::cout << "Menu: " << menu.name << " Price: " << menu.price << std::endl;
//	std::cout << "Drink: " << drink.name << " Price: " << drink.price << " (Hot: " << (drink.hot ? "yes": "no") << ")" << std::endl;
//}