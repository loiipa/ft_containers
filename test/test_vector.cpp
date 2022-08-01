#include <iostream>
#include <string>
#include <vector>
#include "../vector.hpp"

template <class T1, class T2>
void PrintValue(std::string s, T1 val1, T2 val2)
{
	if (val1 == val2)
		std::cout << "\033[0;32m";
	else
		std::cout << "\033[0;31m";
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

		v1.resize(12);
		v1.insert(v1.begin(), 5);
		v1.insert(v1.end()-2, 5);
		v1.insert(v1.end(), 5);
		
		std::cout << "v1 size : " << v1.size() << std::endl;
		std::cout << "v1 capa : " << v1.capacity() << std::endl;
		for (std::vector<int>::iterator it = v1.begin(); it != v1.end(); ++it)
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	}

	// 002 ft::vector test.. just test..
	{
		std::vector<int> svi1;
		ft::vector<int> fvi1;
		PrintValue("vector<int> size", svi1.size(), fvi1.size());

		std::vector<double> svd1(10);
		ft::vector<double> fvd1(10);
		PrintValue("vector<double> max_size", svd1.max_size(), fvd1.max_size());

		std::vector<int> svi2(100, 5);
		ft::vector<int> fvi2(100, 5);
		PrintValue("vector<int> max_size", svi2.max_size(), fvi2.max_size());	//2^62
		PrintValue("vector<int> size", svi2.size(), fvi2.size());
		PrintValue("*vec.begin()", *svi2.begin(), *fvi2.begin());
		PrintValue("*(vec.end()-1)", *(svi2.end()-1), *(fvi2.end() - 1));

		std::vector<int> svi3(svi2.begin(), svi2.end());
		ft::vector<int> fvi3(fvi2.begin(), fvi2.end());
		PrintValue("vector<int> size", svi3.size(), fvi3.size());

		svi2.clear();
		fvi2.clear();
		// svi2.pop_back();
		PrintValue("vec.capacity()", svi2.capacity(), fvi2.capacity());
		PrintValue("vector<int> size", svi2.size(), fvi2.size());

		std::vector<int> svi4(svi3);
		ft::vector<int> fvi4(fvi3);
		PrintValue("vector<int> size", svi4.size(), fvi4.size());


		std::vector<int> svi5(300, 3);
		ft::vector<int> fvi5(300, 3);
		svi5.reserve(1000);
		fvi5.reserve(1000);

		svi4 = svi5;
		fvi4 = fvi5;
		PrintValue("vector<int> size", svi4.size(), fvi4.size());
		PrintValue("vec.front()", svi4.front(), fvi4.front());
		PrintValue("*(vec.rend() - 1)", *(svi4.rend() - 1), *(fvi4.rend() - 1));
		PrintValue("vec.empty()", svi4.empty(), fvi4.empty());
		PrintValue("vec.empty()", svi2.empty(), fvi2.empty());
		PrintValue("vec.capacity()", svi4.capacity(), fvi4.capacity());
		PrintValue("vec.capacity()", svi2.capacity(), fvi2.capacity());
		// svi4.assign(7, 9);
		// fvi4.assign(7, 9);
		// PrintValue("vec.capacity()", svi4.capacity(), fvi4.capacity());

	}

	{
		std::vector<int> svi1(3, 100);
		std::vector<int> svi2(2, 100);
		ft::vector<int> fvi1(3, 100);
		ft::vector<int> fvi2(2, 100);
		PrintValue("vec.operator==", svi1 == svi2, fvi1 == fvi2);
		PrintValue("vec.front()", fvi1.front(), fvi2.front());

		// svi2.assign(3, 200);
		// fvi2.assign(3, 200);
		// PrintValue("vec.operator==", svi1 == svi2, fvi1 == fvi2);
		// PrintValue("vec.operator<", svi1 < svi2, fvi1 < fvi2);
		// PrintValue("vec.operator>", svi1 > svi2, fvi1 > fvi2);
		
		std::swap(svi1, svi2);
		//ft::swap(fvi1, fvi2);
		fvi1.swap(fvi2);

		// PrintValue("vec.front()", fvi1.front(), fvi2.front());

	}

	{
		std::vector<std::string> svi1(3, "hi");
		svi1.reserve(100);
		std::cout << svi1[1] << std::endl;
		std::cout << svi1.at(1) << std::endl;

		ft::vector<std::string> fvi1(3, "hi");
		fvi1.reserve(100);
		std::cout << fvi1[2] << std::endl;
		std::cout << fvi1.capacity() << std::endl;
	}

	{
		std::vector<int> svi1;
		ft::vector<int> fvi1;

		for (int i = 0; i < 10; i++)
		{
			svi1.push_back(i);
			fvi1.push_back(i);
		}
		svi1.insert(svi1.begin() + 1, 3, 3);
		fvi1.insert(fvi1.begin() + 1, 3, 3);
		svi1.insert(svi1.begin() + 1, 20);
		fvi1.insert(fvi1.begin() + 1, 20);
		svi1.insert(svi1.begin()+1, svi1.begin()+3, svi1.begin()+5);
		fvi1.insert(fvi1.begin()+1, fvi1.begin()+3, fvi1.begin()+5);

		PrintValue("vec.capacity()", svi1.capacity(), fvi1.capacity());
		for (int i = 0; i < 10; i++)
		{
			PrintValue("vec[]", svi1[i], fvi1[i]);
		}

	}

}
