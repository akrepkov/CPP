

#ifndef MutantStack_HPP
#define MutantStack_HPP
#include <deque>
#include <iostream>
#include <algorithm>
#include <list>
#include <stack>
#include <vector>

template <class T, typename Container = std::deque<T>> //Underlying container Deque cause I have to
//create a stack instance from MutantStack
class MutantStack: public std::stack<T, Container>{ //inherit from stack
	public:
		MutantStack() : std::stack <T, Container>(){};
		MutantStack(MutantStack& _c): std::stack <T, Container>(_c){};
		virtual ~MutantStack(){};
		MutantStack& operator=(MutantStack& other){
			if (*this != &other){
				std::stack<T, Container>::operator=(other);
			}
			return *this;
		};
		using iterator = typename Container::iterator;
		using const_iterator = typename Container::const_iterator;
		using reverse_iterator = typename Container::reverse_iterator;
		using const_reverse_iterator = typename Container::const_reverse_iterator;
		iterator    begin() { return this->c.begin(); } //C - container
		iterator    end() { return this->c.end(); }
		// const_iterator cbegin() const { return this->c.cbegin(); }
		// const_iterator cend() const { return this->c.cend(); }
		reverse_iterator rbegin() { return this->c.rbegin(); }
		reverse_iterator rend() { return this->c.rend(); }
		// const_reverse_iterator crbegin() const { return this->c.crbegin(); }
		// const_reverse_iterator crend() const { return this->c.crend(); }
};


#endif
