#include "StackDouble.h"

StackDouble::StackDouble(){
	top = nullptr;
}

StackDouble::~StackDouble(){
	while (!isEmpty()) {
		this->pop();
	}
}

bool StackDouble::isEmpty()
{
	return top==nullptr;
}

void StackDouble::push(const double _data){
	NodeDouble* nuevo;
	try {
		nuevo = new NodeDouble();
	}
	catch (std::bad_alloc exception) {
		return;
	}
	nuevo->data = _data;
	nuevo->next = top;
	top = nuevo;
}

const double StackDouble::pop()
{	if (isEmpty())
	return -1;
	char _data;
	NodeDouble* tmp;
	_data = top->data;
	tmp = top;
	top = top->next;
	delete tmp;
	tmp = nullptr;
	return _data;
}

const double StackDouble::peek()
{
	return (!isEmpty() ? top->data : -1);
}
