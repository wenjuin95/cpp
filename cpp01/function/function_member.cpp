# include <iostream>

//syntax
//return_type (ClassName::*pointer_name)(argument) = &className::function_name;
/**
 * return_type              : return type of the function
 * ClassName                : name of the class
 * pointer_name             : name of the pointer
 * argument                 : argument of the function
 * &ClassName::function_name: address of the function being assigned to the pointer
*/

//class Math
//{
//	public:
//		int nb;
//		Math(): nb(0) {}
//		int	add(int a, int b) { return a + b; }
//};

//int main(void)
//{
//	Math math;
//	int (Math::*add_ptr)(int, int) = &Math::add;
//	int res = (math.*add_ptr)(20, 20);
//	std::cout << res << std::endl;
//}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Msg
{
	public:
		void say_hi(void) { std::cout << "Hi" << std::endl; }
		void say_bye(void) { std::cout << "Bye" << std::endl; }
		void which_msg(std::string msg);
};

void	Msg::which_msg(std::string msg)
{
	void	(Msg::*func_ptr[2])() = { &Msg::say_hi, &Msg::say_bye };
	std::string	msg_lst[2] = { "h", "b" };

	int	i = 0;
	while (i < 2)
	{
		if (msg == msg_lst[i])
			(this->*func_ptr[i])();
		i++;
	}
}

int main(int ac, char **av)
{
	Msg msg;
	if (ac != 2)
	{
		std::cout << "Usage: ./function_member [h/b]" << std::endl;
		exit(1);
	}
	msg.which_msg(av[1]);
}
