#include <iostream>
#include <string>

// class Parent{
// 	protected:
// 		int parent_value;
// 	public:
// 		Parent(int value): parent_value(value){};
// 		virtual ~Parent(){}; //need for polimorphysm (to make Parent abstract)
// 		int getValue(){return parent_value;}
// };

// class Child : public Parent{
// 	protected:
// 		std::string child_name;
// 	public:
// 		Child(int value, std::string name) : Parent(value), child_name(name){};
// 		~Child(){};
// 		const std::string& getName(){return child_name;}
// };

// Parent* getObject(bool return_child){
// 	if (return_child)
// 		return new Child(10, "anna");
// 	else
// 		return new Parent(5);
// }


// int main(){

// 	// b = &a -> *b = *&a;
// 	// Parent *p = getObject(false);
// 	// Child *ch = dynamic_cast<Child*>(p);
// 	// if (ch) //Правило: Всегда делайте проверку результата динамического приведения на нулевой указатель. 
// 	// 	std::cout << "The name of the child is " << ch->getName() << std::endl;
// 	// delete p;
// 	return 0;
// }

// // dynamic_cast_clr.cpp
// // compile with: /clr

class A{
	public:
	virtual void test(){
		std::cout << "In A" << std::endl;
	}
};
class B : public A{
	public:
	virtual void test(){
		std::cout << "In B" << std::endl;
	}	
	virtual void test2(){
		std::cout << "In B" << std::endl;
	}	
};
class C : public B{
	public:
	virtual void test(){
		std::cout << "In C" << std::endl;
	}	
};

void global_test(A& a){
	C &c = dynamic_cast<C&>(a);
	std::cout << "In C" << std::endl;
}

int main(){
	A* pa = new C;
	pa->test();
	B* pb = dynamic_cast<B*>(pa);
	if (pb)
		pb->test();
    C * pc = dynamic_cast<C *>(pa);
    if (pc)
        pc->test2();
	B myObj;
	global_test(myObj);
	return 0;
}

//convert Child to Parent - implicit conversion, static_cast

//Parent to Child - dynamic_cast

