#include "Nodo.h"

Nodo::Nodo() : 
	arriba(nullptr), derecha(nullptr), abajo(nullptr), izquierda(nullptr), dato(0) {}

Nodo::Nodo(nodo _arriba, nodo _derecha, nodo _abajo, nodo _izquierda, int _dato) :
	arriba(_arriba), derecha(_derecha), abajo(_abajo), izquierda(_izquierda), dato(_dato) {}

Nodo::~Nodo() {}

/*
	Devuelve el nodo segun el caracter seleccionado
	u(up) = arriba
	r(right) = derecha
	d(down) = abajo
	l(left) = izquierda
*/
Nodo::nodo Nodo::getNodo(char caracter) {
	nodo ptr = nullptr;
	switch (caracter) {
	case 'u':
		ptr = arriba;
		break;
	case 'r':
		ptr = derecha;
		break;
	case 'd':
		ptr = abajo;
		break;
	case 'l':
		ptr = izquierda;
		break;
	}
	return ptr;
}

/*
	Modifica el puntero del nodo segun el caracter seleccionado
	u(up) = arriba
	r(right) = derecha
	d(down) = abajo
	l(left) = izquierda
*/
void Nodo::setNodo(nodo nodo, char caracter) {
	switch (caracter) {
	case 'u':
		arriba = nodo;
		break;
	case 'r':
		derecha = nodo;
		break;
	case 'd':
		abajo = nodo;
		break;
	case 'l':
		izquierda = nodo;
		break;
	}
}

int Nodo::getDato() { return dato; }

void Nodo::setDato(int _dato) { dato = _dato; }
