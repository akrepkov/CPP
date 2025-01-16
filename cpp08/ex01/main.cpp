
#include "Span.hpp"
#include <bits/stdc++.h> 

bool compareSpan(int s1, int s2){
	return (s1 < s2);
}

int main(){
	unsigned int max = 10;
	Span num(max);
	try{
		num.addNumber(-1);
		num.addNumber(-10);
		int amountOfNum = 1000;
		num.addIteration(amountOfNum);
		num.addNumber(-100);
	} catch (const char* exception){
		std::cout << exception << std::endl;
	}
	std::vector<int> copyV = num.getVector();
	// std::cout << "Numbers in the vector: " << std::endl;
	// for (int i : copyV)
	// 	std::cout << i << " ";
	sort(copyV.begin(), copyV.end(), compareSpan);
	// std::cout << "\nNumbers after the sorting: " << std::endl;
	// for (int i : copyV)
	// 	std::cout << i << " ";
	// std::cout << '\n';
	try{
		std::cout  << num.shortestSpan() << std::endl;
		std::cout << num.longestSpan() << std::endl;
	}catch (const char* message){
		std::cout << message << std::endl;
	}
	return 0;
}
