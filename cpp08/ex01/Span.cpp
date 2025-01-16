

#include "Span.hpp"
#include <iostream>
#include <limits>
#include <bits/stdc++.h> 
#include <exception>
Span::Span(): N(0){};
Span::Span(unsigned int n) : N(n){
};
Span::~Span(){};
Span& Span::operator=(const Span& copy){
	if (this != &copy){
		this->N = copy.N;
		this->V = copy.V;
	}
	return *this;
}
Span::Span(const Span& copy){
	*this = copy;
}

void Span::addNumber(int number){
	if (V.size() >= N)
		throw "Can't add more elements";
	V.push_back(number);
}

std::vector<int> Span::getVector(){
	return V;
}

int Span::shortestSpan(){
	if (V.size() < 2)
		throw "No span can be found";
	std::sort(this->V.begin(), this->V.end());
	int min = std::numeric_limits<int>::max();
	int diff;
	for (int i = 0; i < int(V.size()) - 1; i++){
		diff = V[i + 1] - V[i];
		if (diff < min)
			min = diff;
	}
	return (min);
}

int Span::longestSpan(){
	if (V.size() < 2)
		throw "No span can be found";
	return (abs(V[V.size() - 1] - V[0]));
}

void Span::addIteration(int mem){
	if (mem < 0)
		throw "Can't accept negative number";
	srand(time(NULL));
	std::vector<int> numbers(mem);
	auto it = 0;
	for (int& num : numbers){
		if (V.size() + it >= N){
			numbers.resize(it);
			break;
		}
		++it;
		num = rand() % (2 * 100000) - 100000;
	}
	V.insert(V.end(), numbers.begin(), numbers.end());
	if (it < mem)
		throw "Can't add more elements";
	// std::vector<int>::iterator i = V.begin();
	// std::vector<int>::iterator end = V.begin() + mem;
	// while (i != end){
	// 	if (V.size() >= N)
	// 		throw "Can't add more elements";
	// 	int t = rand() % (2 * mem) - mem;
	// 	V.push_back(t);
	// 	i++;
	// }	
}
