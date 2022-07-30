#include <map>
#include <iostream>

int main()
{
	std::map<int, int> in_out;
	in_out.insert(std::make_pair(1,1));
	in_out.insert(std::make_pair(100, 5));
	in_out.insert(std::make_pair(5, 10));
	for (auto it = in_out.begin(); it != in_out.end(); ++it)
		std::cout << it->first << " " << it->second << std::endl;

}
