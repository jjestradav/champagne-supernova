#include "StackInt.h"

StackInt::StackInt(){
	top = nullptr;
}

StackInt:: ~StackInt(){
	while (!isEmpty()) {
		this->pop();
	}
}

bool StackInt::isEmpty()
{
	return (top==nullptr);
}

void StackInt::push(const int _data){
	NodeInt* nuevo;
	try {
		nuevo = new NodeInt();
	}
	catch (std::bad_alloc exception) {
		return;
	}
	nuevo->data = _data;
	nuevo->next = top;
	top = nuevo;
}

const int StackInt::pop(){
	if (isEmpty())
		return -1;
	int _data;
	NodeInt* tmp;
	_data = top->data;
	tmp = top;
	top = top->next;
	delete tmp;
	tmp = nullptr;
	return _data;
}

const int StackInt::peek()
{
	return (!isEmpty() ? top->data : -1);
}
