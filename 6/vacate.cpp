#include <iostream>
 
class Parent
{
public:
	Parent() {}
 
	virtual void print() const { std::cout << "Parent";  }
};
 
class Child: public Parent
{
public:
	Child() {}
 
	virtual void print() const { std::cout << "Child"; }
};
 
int main()
{
	Child ch;
	Parent parent;
	Parent &p = ch;
	p.print(); // вызывается Child::print()
 
	return 0;
}