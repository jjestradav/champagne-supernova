#ifndef NODO_H
#define NODO_H

class Nodo {
public:
	typedef Nodo* nodo; // Define un alias para el tipo Nodo*
	Nodo();
	Nodo(nodo _arriba, nodo _derecha, nodo _abajo, nodo _izquierda, int _dato);
	~Nodo();
	nodo getNodo(char caracter);
	void setNodo(nodo nodo, char caracter);
	int getDato();
	void setDato(int _dato);
private:
	nodo arriba;
	nodo derecha;
	nodo abajo;
	nodo izquierda;
	int dato;
};
#endif
