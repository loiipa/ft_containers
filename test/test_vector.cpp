#include <iostream>

#include <vector>
#include "../vector.hpp"

template <class T1, class T2>
void PrintValue(std::string s, T1 val1, T2 val2)
{
	std::cout << s << "\t" << val1 << "\t" << val2 << "\t";
	if (val1 == val2)
		std::cout << "(==)" << std::endl;
	else
		std::cout << "(!=)" << std::endl;
}

int main()
{
	// 001 std::vector size vs capa
	{
		std::vector<int> v1;
		v1.reserve(10);
		v1.push_back(1);
		std::cout << "v1 size : " << v1.size() << std::endl;
		std::cout << "v1 capa : " << v1.capacity() << std::endl;
	}

	// 002 ft::vector test.. just test..
	{
		std::vector<int> svi1;
		ft::vector<int> fvi1;
		PrintValue("vector<int> size", svi1.size(), fvi1.size());

		std::vector<double> svd1(10);
		ft::vector<double> fvd1(10);
		PrintValue("vector<double> max_size", svd1.max_size(), fvd1.max_size());

		std::vector<int> svi2(10);
		ft::vector<int> fvi2(10);
		PrintValue("vector<int> max_size", svi2.max_size(), fvi2.max_size());	//2^62
		PrintValue("vector<int> size", svi2.size(), fvi2.size());

		svi2.clear();
		fvi2.clear();
		PrintValue("vector<int> size", svi2.size(), fvi2.size());

	}

}
