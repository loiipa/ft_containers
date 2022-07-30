#include <iostream>
#include <string>
#include <algorithm>
#include "../algorithm.hpp"

int main()
{
	std::string s1 = "cjang";
	std::string s2 = "cjang2";
	std::string s3 = "cjang3";

	if (ft::equal(s1.begin(), s1.end(), s2.begin()))
		std::cout << "true1" << std::endl;

	if (ft::equal(s2.begin(), s2.end(), s3.begin()))
		std::cout << "true2" << std::endl;
}
