#include <iostream>
#include <string>
#include <algorithm>
#include "../algorithm.hpp"

int main()
{
	std::string s1 = "cjang";
	std::string s2 = "cjang2";
	std::string s3 = "cjang3";

	if (ft::lexicographical_compare(s1.begin(), s1.end(), s2.begin(), s2.end()))
		std::cout << "true1" << std::endl;

	if (ft::lexicographical_compare(s2.begin(), s2.end(), s3.begin(), s3.end()))
		std::cout << "true2" << std::endl;
}
