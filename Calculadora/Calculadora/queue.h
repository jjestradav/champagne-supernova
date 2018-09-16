
#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include <stdlib.h>

template<class T>
struct NodeQ {
	T* data;
	struct NodeQ<T>* next;
};
template<class T>
class queue{
private:
	struct NodeQ<T>* head;
	struct NodeQ<T>* tail;
	bool isEmpty();
public:
	queue();
	~queue();
	void enqueue(const T*);
	T* dequeue();
	T* next();
};
#endif // QUEUE_H

template<class T>
inline bool queue<T>::isEmpty()
{
	return (head==nullptr);
}

template<class T>
inline queue<T>::queue(){
	head = nullptr;
	tail = nullptr;
}

template<class T>
inline queue<T>::~queue(){
}

template<class T>
inline void queue<T>::enqueue(const T * _data) {
	NodeQ<T>* nuevo;
	try {
		nuevo = new NodeQ<T>;
	}
	catch (std::bad_alloc exception) {
		return;
	}
	nuevo->data = _data; // Error	C2440	'=': cannot convert from 'const T *' to 'T *'
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
template<class T>
inline T * queue<T>::dequeue(){
	if (isEmpty()) 
	return nullptr;
	NodeQ<T>* tmp;
	T* _data;
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

template<class T>
inline T * queue<T>::next(){
	if (isEmpty())
		return nullptr;
	return head->data;
}

