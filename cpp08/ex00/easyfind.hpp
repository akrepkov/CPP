

#ifndef easyfind_hpp
#define easyfind_hpp
#include <algorithm>

template <typename T>
void easyfind(T container, int a)
{
	auto it = std::find(container.begin(), container.end(), a);
	if (it != container.end()){
			std::cout << a << " found at the position " << std::distance(container.begin(), it) << std::endl;
			return ;
	}
	else{
		throw std::out_of_range("Element not found");
	}
}

#endif