#ifndef STACK_H
#define STACK_H
#include <iostream>
template<class T>
struct nodeS {
	T* data;
	struct nodeS* next;
};
template <class T>
class Stack {
private:
	 nodeS<T>* top;
	bool isEmpty();
public:
	Stack();
	~Stack();
	void push(const T*);
	T* pop();
	T* peek();
};
#endif 

template<class T>
inline bool Stack<T>::isEmpty(){
	return !top;
}

template<class T>
inline Stack<T>::Stack(){
	top = nullptr;
}

template<class T>
inline Stack<T>::~Stack(){

}

template<class T>
inline void Stack<T>::push(const T * item) {
	 nodeS<T>* nuevo;
	try {
		nuevo = new nodeS<T>;
	}
	catch (std::bad_alloc exception) {
		return;
	}
	nuevo->data = *item;
	nuevo->next = top;
	top = nuevo;
}

template<class T>
inline T * Stack<T>::pop(){
	if (isEmpty())
		return nullptr;
	T* _data;
	nodeS<T>* tmp;
	_data = top->data;
	tmp = top;
	top = top->next;
	delete tmp;
	tmp = nullptr;
	return _data;
}

template<class T>
inline T * Stack<T>::peek(){
	return (!isEmpty()? top->data:nullptr);
}

