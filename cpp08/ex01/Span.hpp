
#ifndef span_hpp
#define span_hpp
#include <vector>
#include <iostream> 


class Span{
	private:
		unsigned int N;
		std::vector<int> V;
	public:
		Span();
		Span(unsigned int n);
		~Span();
		Span& operator=(const Span& copy);
		Span(const Span& copy);
		void addNumber(int nuumber);
		std::vector<int> getVector();
		void addIteration(int mem);
		int shortestSpan();
		int longestSpan();

};


#endif
/*
Composition:

class Engine {
    // Engine details
};

class Car {
private:
    Engine m_engine; // Regular member variable, owned by Car
public:
    Car() { Engine is created with Car }
    ~Car() { Engine is destroyed with Car }
};


Agregation:
class Worker {
    // Worker details
};

class Department {
private:
    Worker* m_worker; // Pointer to a Worker that exists outside of Department
public:
    Department(Worker* worker) : m_worker(worker) { Worker is assigned, but not created }
    // Department does not destroy Worker
};

Composition: A house and its rooms. If the house is destroyed, the rooms are destroyed as well.
Aggregation: A classroom and students. If the classroom is closed, the students still exist and can be part of other classrooms.

*/