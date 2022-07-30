#include <type_traits>
#include "../type_traits.hpp"
#include <iostream>

// namespace std = ft;

struct T
{
	enum
	{
		int_t,
		float_t
	} type;
	
	template <typename Integer,
		typename ft::enable_if<std::is_integral<Integer>::value, T>::type* = nullptr
		>
		T(Integer) : type(int_t)
		{
			std::cout << "integer" << std::endl;
		}

	template <typename Floating,
		typename ft::enable_if<std::is_floating_point<Floating>::value, T>::type* = nullptr
		>
		T(Floating) : type(float_t)
		{
			std::cout << "floating" << std::endl;
		}
};

int main()
{
	T T1(3);
	T T2(3.5);
}
