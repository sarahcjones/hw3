#include "heap.h"
#include <functional>
#include <iostream>

int main()
{
	Heap<int> heap;
	heap.push(9);
	heap.push(9);
	std::cout << heap.top() << std::endl;
	std::cout << &heap.top() << std::endl;
	std::cout << "*" << std::endl;
	heap.push(20);
	std::cout << heap.top() << std::endl;
	std::cout << &heap.top() << std::endl;
	std::cout << "*" << std::endl;

	heap.pop();
	std::cout << heap.top() << std::endl;
	std::cout << &heap.top() << std::endl;
	std::cout << "*" << std::endl;
	heap.pop();
	std::cout << heap.top() << std::endl;
	std::cout << &heap.top() << std::endl;
	std::cout << "*" << std::endl;

	// std::cout << heap.size() << std::endl;
	// for (unsigned int i = 0; i < 1; i++)
	// {
	// 	std::cout << heap.top() << std::endl;
	// 	std::cout << &heap.top() << std::endl;
	// }
}