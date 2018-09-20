#include "Calculadora.h"

Calculadora::Calculadora() { }

Calculadora::~Calculadora() { }

string Calculadora::capturarExpresion(istream& entrada) {
	string expresion;
	cout << "Digite una expresion interfija y presione <ENTER>: " << endl;

	if (entrada) {
		expresion.clear();
		getline(entrada, expresion);
		entrada.clear();
	}
	return expresion;
}

void Calculadora::convertirACola(string expresion) {
	string numTemp;
	bool bandera = false; // para controlar si lo primero y lo ultimo digitado es un entero
	for (size_t i = 0; i < expresion.size(); i++) {
		if (isdigit(expresion[i])) {
			numTemp.append(1, expresion[i]);
			bandera = true;
		}
		else {
			if (bandera)
				cola.enqueue(&numTemp);
			numTemp = "";
			bandera = false;
			cola.enqueue(&string(1, expresion[i]));
		}
	}
	if (bandera) // durante el for inserta solamente si se encuentra con un operando
		cola.enqueue(&numTemp);
}

void Calculadora::imprimirCola(queue<string> cola) {

}

bool Calculadora::esNumero(string numero)
{
	for (size_t i = 0; i < numero.size(); i++) {
		if (!isdigit(numero[i]))
			return false;
	}
	return true;
}

int Calculadora::precedencia(char c) {
	if (c == '(')
		return 1;
	if (c == '+' || c == '-')
		return 2;
	if (c == '*' || c == '/')
		return 3;
	return -1;
}

/*
	
*/
void Calculadora::convertirPosfija(queue<string>& cola) {
	char c;
	string a;
	Stack<char> pila;

	while (!cola.empty()) {
		a = cola.front();
		if (esNumero(a))
			colaPosfija.push(a);
		else if (a[0] == '(')
			pila.push(a[0]);
		else if (a[0] == ')')
			while ((c = pila.top()) != '(') {
				pila.pop();
				colaPosfija.push(string(1, c));
			}
		else {
			while (!pila.empty() && precedencia(pila.top()) >= precedencia(a[0])) {
				colaPosfija.push(string(1, pila.top()));
				pila.pop();
			}
			pila.push(a[0]);
		}
		cola.pop();
	}
	while (!pila.empty()) {
		// mete a la cola TODO lo que le resta a la pila
		// hay momentos donde quedan '(' "perdidos"
		// este parentesis jode el proceso cuando se evalua
		if (pila.top() != '(')
			colaPosfija.push(string(1, pila.top()));
		pila.pop();
	}
}
