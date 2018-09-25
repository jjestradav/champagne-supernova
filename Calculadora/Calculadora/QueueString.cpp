#include "QueueString.h"

QueueString::QueueString(){
	head = nullptr;
	tail = nullptr;
}

QueueString::~QueueString(){
	while (!isEmpty()) {
		this->dequeue();
	}
}

bool QueueString::isEmpty()
{
	return (head == nullptr);
}

void QueueString::enqueue(const std::string _data){
	NodeQS* nuevo;
	try {
		nuevo = new NodeQS();
	}
	catch (std::bad_alloc exception) {
		return;
	}
	nuevo->data = _data;
	nuevo->next = nullptr;
	if (isEmpty()) {
		head = nuevo;
		tail = nuevo;
	}
	else {
		tail->next = nuevo;
		tail = nuevo;
	}

}

const std::string QueueString::dequeue(){
	if (isEmpty())
		return "vacia";
	NodeQS *tmp;
	std::string _data;
	tmp = head;
	_data = head->data;
	head = head->next;
	if (head == nullptr) {
		tail = nullptr;
	}
	delete tmp;
	tmp = nullptr;
	return _data;
}

const std::string QueueString::next(){
	if (isEmpty())
		return ("vacia");
	return head->data; 
}
