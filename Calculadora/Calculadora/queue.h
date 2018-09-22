
#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include <stdlib.h>

template<class T>
struct NodeQ {
	const T* data;
	struct NodeQ<T>* next;
};
template<class T>
class queue {
private:
	struct NodeQ<T>* head;
	struct NodeQ<T>* tail;

public:
	queue();
	~queue();
<<<<<<< HEAD
	void enqueue(const T*);
	const T* dequeue();
	const T* next();
=======
	bool isEmpty();
	void enqueue(T&);
	T& dequeue();
	T& next();
>>>>>>> 20287151bdbb5ccd83fdb4893582f9cf426013a4
};
#endif // QUEUE_H

template<class T>
inline bool queue<T>::isEmpty()
{
	return (head == nullptr);
}

template<class T>
inline queue<T>::queue() {
	head = nullptr;
	tail = nullptr;
}

template<class T>
inline queue<T>::~queue() {
}

template<class T>
inline void queue<T>::enqueue(T& _data) {
	NodeQ<T>* nuevo;
	try {
		nuevo = new NodeQ<T>;
	}
	catch (std::bad_alloc exception) {
		return;
	}
	nuevo->data = &_data; // Error	C2440	'=': cannot convert from 'const T *' to 'T *'
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
<<<<<<< HEAD
inline const T * queue<T>::dequeue(){
	if (isEmpty()) 
	return nullptr;
	NodeQ<T>* tmp;
	const T* _data;
	tmp = head;
	_data = head->data;
	head = head->next;
	if (head == nullptr) {
		tail = nullptr;
=======
inline T & queue<T>::dequeue() {
	if (!isEmpty()) {
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
		return *_data;
>>>>>>> 20287151bdbb5ccd83fdb4893582f9cf426013a4
	}
}

template<class T>
<<<<<<< HEAD
inline const T * queue<T>::next(){
	if (isEmpty())
		return nullptr;
	return head->data;
=======
inline T& queue<T>::next() {
	if (!isEmpty())
		return *head->data;

>>>>>>> 20287151bdbb5ccd83fdb4893582f9cf426013a4
}

