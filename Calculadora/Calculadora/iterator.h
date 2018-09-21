#include "List.h"
#ifndef ITERATOR_H
#define ITERATOR_H
template<class T>
class iterator {
public:
	iterator(Node<T>*);
	virtual ~iterator();
	 bool empty() const ;
	 const T* next() ;
private:
	Node<T>* actual;
};
#endif // ITERATOR_H

template<class T>
inline iterator<T>::iterator(Node<T>* _actual){
	actual = _actual;
}

template<class T>
inline iterator<T>::~iterator(){

}

template<class T>
inline bool iterator<T>::empty() const{
	return actual!=nullptr;
}

template<class T>
inline const T * iterator<T>::next(){
	const T* r = nullptr;
	if (empty()) {
		r = actual->data;
		actual = actual->next;
	}
	return r;
}
