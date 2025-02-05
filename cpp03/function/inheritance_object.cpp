#include <iostream>
#include <string>

class Menu
{
	private:
		std::string name;
		int price;
	public:
		Menu( void )
		{
			std::cout << "Menu default constructor" << std::endl;
		}

		Menu(std::string name, int price)
		{
			std::cout << "Menu constructor" << std::endl;
			this->name = name;
			this->price = price;
		}

		~Menu()
		{
			std::cout << "Menu destructor" << std::endl;
		}

		std::string getName()
		{
			return name;
		}

		int getPrice()
		{
			return price;
		}

};

class Drink : public Menu
{
	private:
		bool hot;
	public:
		Drink( void ) : Menu()
		{
			std::cout << "Drink default constructor" << std::endl;
		}

		Drink(std::string name, int price, bool hot) : Menu(name, price)
		{
			std::cout << "Drink constructor" << std::endl;
			this->hot = hot;
		}

		~Drink()
		{
			std::cout << "Drink destructor" << std::endl;
		}

		bool getHot()
		{
			return hot;
		}
};

int main()
{
	//Menu menu("Hamburger", 1000);
	Drink drink("Coke", 500, true);

	//std::cout << "Menu: " << menu.getName() << " Price: " << menu.getPrice() << std::endl;
	std::cout << "Drink: " << drink.getName() << " Price: " << drink.getPrice() << " (Hot: " << (drink.getHot() ? "yes": "no") << ")" << std::endl;
}