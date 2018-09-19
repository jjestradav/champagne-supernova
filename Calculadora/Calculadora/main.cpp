#include <iostream>
#include "queue.h"
#include "Stack.h"
int main() {
	Stack<int> pila;
	queue<int> cola;
	int *x = new int (1);
	cola.enqueue(x);
	pila.push(x);
	std::cout << *pila.pop() << std::endl;
	std::cout << *cola.dequeue() << std::endl;
	system("pause");
	return 0;
}