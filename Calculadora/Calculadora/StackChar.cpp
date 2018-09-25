#include "StackChar.h"

StackChar::StackChar(){
	top = nullptr;
}

StackChar::~StackChar(){
	while (!isEmpty())
	{
		pop();
	}
}

bool StackChar::isEmpty()
{
	return top == nullptr;
}

void StackChar::push(const char _data){
	NodeChar* nuevo;
	try {
		nuevo = new NodeChar();
	}
	catch (std::bad_alloc exception) {
		return;
	}
	nuevo->data = _data;
	nuevo->next = top;
	top = nuevo;
}

const char StackChar::pop(){
	if (isEmpty())
		return '-1';
	char _data;
	NodeChar* tmp;
	_data = top->data;
	tmp = top;
	top = top->next;
	delete tmp;
	tmp = nullptr;
	return _data;
}

const char StackChar::peek()
{
	return (!isEmpty() ? top->data : '-1');
}
