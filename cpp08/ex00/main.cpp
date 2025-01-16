#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <queue>
#include <deque>
#include <forward_list>
#include "easyfind.hpp"


void easyfind(std::queue<int> q, int a){
	int i = 0;
	while(!q.empty()){
		if(q.front() == a){
			std::cout << "Found at the position " << i << std::endl;
			return ;
		}
		i++;
		q.pop();
	}
	if (q.empty())
		throw std::out_of_range("Not found");
}

int main(){
	try{
		std::vector<int> v = {1,2,3, 5, 8, 1};
		std::cout << "\033[2;33;20mVector\033[0m\t\t {1,2,3, 5, 8, 1}" << std::endl;
		easyfind(v, 3);
		easyfind(v, 0);
	} catch (std::exception &e){
		std::cerr << e.what() << std::endl;
	}
	std::cout << "\033[2;33;20mEmpty Vector\033[0m\t\t" << std::endl;
	try{
		std::vector<int> v1;
		easyfind(v1, 0);
	} catch (std::exception &e){
		std::cerr << e.what() << std::endl;
	}
	std::cout << "\033[2;33;20mArray\033[0m\t\t {4,6,5,3,7}" << std::endl;
	try{
		std::array<int, 5> arr = {4,6,5,3,7};
		easyfind(arr, 6);
	} catch (std::exception &e){
		std::cerr << e.what() << std::endl;
	}
	std::cout << "\033[2;33;20mList\033[0m\t\t {4,6,5,3,7}" << std::endl;
	try{
		std::list<int> l = {4,6,5,3,7};
		easyfind(l, 7);
	} catch (std::exception &e){
		std::cerr << e.what() << std::endl;
	}
	std::cout << "\033[2;33;20mForward list\033[0m\t\t {14,6,51,3,7}" << std::endl;
	try{
		std::forward_list<int> forward_l = {14,6,51,3,7};
		easyfind(forward_l, 0);
	} catch (std::exception &e){
		std::cerr << e.what() << std::endl;
	}
	std::cout << "\033[2;33;20mQueue\033[0m\t\t {3,6,3}" << std::endl; //FIFO
	try{
		std::queue<int> q;
		q.push(3);
		q.push(6);
		q.push(3);
		easyfind(q, 6);
	} catch (std::exception &e){
		std::cerr << e.what() << std::endl;
	}
	std::cout << "\033[2;33;20mDeque\033[0m\t\t {3,6,3,4}" << std::endl;
	try{
		std::deque<int> dq;
		dq.push_back(3);
		dq.push_back(6);
		dq.push_back(3);
		dq.push_back(4);
		easyfind(dq, 4);
		easyfind(dq, 12);
	} catch (std::exception &e){
		std::cerr << e.what() << std::endl;
	}
	return 0;
}

// Последовательные контейнеры
// Класс deque (или просто «дек») — это двусторонняя очередь, 
// который может расти с обоих концов. 
// deq.push_back(count); // вставляем числа в конец массива
// deq.push_front(10 - count); // вставляем числа в начало массива


// Ассоциативные контейнеры — это контейнерные классы, которые автоматически сортируют все свои элементы 
// (в том числе и те, которые добавляете вы).
// set — это контейнер, в котором хранятся только уникальные элементы.
// multiset — это set, но в котором допускаются повторяющиеся элементы.
// map (или «ассоциативный массив») — это set, в котором каждый элемент 
// 	является парой «ключ-значение». «Ключ» используется для сортировки и индексации 
// 	данных и должен быть уникальным, а «значение» — это фактические данные.
// multimap (или «словарь») — это map, который допускает дублирование ключей. 
// 	Все ключи отсортированы в порядке возрастания, и вы можете посмотреть значение 
// 	по ключу.


// Адаптеры — это специальные предопределенные контейнерные классы, 
// которые адаптированы для выполнения конкретных заданий.
// stack (стек) — это контейнерный класс, элементы которого работают по принципу LIFO 
// (англ. «Last In, First Out» = «последним пришел, первым ушел»), т.е. элементы добавляются (вносятся) в конец контейнера 
// и удаляются (выталкиваются) оттуда же (из конца контейнера). 
// queue (очередь) — это контейнерный класс, элементы которого работают по принципу FIFO (англ. «First In, First Out» = «первым пришел, первым ушел»), т.е. элементы добавляются (вносятся) в конец контейнера, 
// но удаляются (выталкиваются) из начала контейнера.
// priority_queue (очередь с приоритетом) — это тип очереди, в которой все элементы отсортированы (с помощью оператора сравнения <). 
// При добавлении элемента, он автоматически сортируется. 

