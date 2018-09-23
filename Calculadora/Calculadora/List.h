//Esta clase lista se puede utilizar para hacer un historial
//de las operaciones que se han realizado durante la ejecucion 
//de el programa. 
#ifndef LIST_H
#define LIST_H
#include <iostream>
template <class T>
class iterator;
template<class T>
struct Node {
	T data;
	Node<T>* next;
};

template <class T>
class List {
private:
	Node<T>* first;
	int tam;
public:
	List();
	~List();
	void push_front(const T& _data);
	void push_back(const T& _data);
	const T& pop_front();
	const T& pop_back();
	//T* pop(int pos); creo que esta operacion no es necesaria
	void deletelist();
	bool isEmpty();
	/*iterator<List>* getiterator();*/
};
#endif // !LIST_H

template<class T>
inline List<T>::List() {
	first = nullptr;
}

template<class T>
inline List<T>::~List() {
	deletelist();
}

template<class T>
inline void List<T>::push_front(const T & _data) {
	Node<T>* nuevo;
	try {
		nuevo = new Node<T>();
	}
	catch (std::bad_alloc exception) {
		return;
	}
	nuevo->data = _data;
	nuevo->next = nullptr;
	if (isEmpty())
		first = nuevo;
	else {
		nuevo->next = first;
		first = nuevo;
	}
	tam++;
}

template<class T>
inline void List<T>::push_back(const T & _data) {
	Node<T>* nuevo;
	try {
		nuevo = new Node<T>;

	}
	catch (std::bad_alloc exception) {
		return;
	}
	nuevo->data = _data;
	nuevo->next = nullptr;
	Node<T>* p = first;
	while (p->next != nullptr) {
		p = p->next;
	}
	p->next = nuevo;
}

template<class T>
inline const T & List<T>::pop_front() {
	if (isEmpty())
		return nullptr;
	Node<T>* p = first;
	T _data;
	_data = p->data;
	first = first->next;
	delete p;
	p = nullptr;
	return _data;
}

template<class T>
inline const T & List<T>::pop_back() {
	if (isEmpty())
		return nullptr;
	Node<T>* p = first;
	Node<T>* q;
	T _data;
	while (p->next != nullptr) {
		q = p;
		p = p->next;
	}
	_data = p->data;
	q->next = nullptr;
	delete p;
	p = nullptr;
	return _data;
}



template<class T>
inline void List<T>::deletelist() {
	while (this->pop_front() != nullptr);
}

template<class T>
inline bool List<T>::isEmpty()
{
	return first == nullptr;
}

//template<class List>
//template<class T>
//inline iterator<List>* List<T>::getiterator(){
//	return NULL;
//}

