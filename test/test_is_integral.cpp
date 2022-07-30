#include <type_traits>
#include "../type_traits.hpp"
#include <iostream>

int main()
{
	if (std::is_integral<int>())
		std::cout << "int 1 " << std::is_integral<int>() << std::endl;
	// if (std::integral_constant<int, 2.5>())
	if (std::integral_constant<int, 2>())
		std::cout << "int 2 " << std::integral_constant<int, 2>() << std::endl;
	if (ft::is_integral<int>())
		std::cout << "int!" << ft::is_integral<unsigned int>() << std::endl;
	if (ft::integral_constant<int, 5>())
		std::cout << "int 5 " << ft::integral_constant<int, 5>() << std::endl;
}
