#include "Calculadora.h"

Calculadora::Calculadora() {
}

Calculadora::~Calculadora() { }

void Calculadora::calcular() {
	string expresion = capturarExpresion(cin);
	convertirACola(expresion);
	imprimirCola(cola);
}

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
				cola.enqueue(*new string(numTemp));
			numTemp = "";
			bandera = false;
			string* a = new string(1, expresion[i]);
			cola.enqueue(*a);
		}
	}
	if (bandera) // durante el for inserta solamente si se encuentra con un operando
		cola.enqueue(*new string(numTemp));
}

void Calculadora::imprimirCola(queue<string>& cola) {
	while (!cola.isEmpty()) 
		cout << cola.dequeue() << ", ";
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


//void Calculadora::convertirPosfija(queue<string>& cola) {
//	char c;
//	string a;
//	Stack<char> pila;
//
//	while (!cola.isEmpty()) {
//		a = cola.next();
//		if (esNumero(a))
//			colaPosfija.enqueue(a);
//		else if (a[0] == '(')
//			pila.push(a[0]);
//		else if (a[0] == ')')
//			while ((c = pila.top()) != '(') {
//				pila.pop();
//				string a(1, c);
//				colaPosfija.enqueue(a);
//			}
//		else {
//			while (!pila.empty() && precedencia(pila.top()) >= precedencia(a[0])) {
//				string a(1, pila.top());
//				colaPosfija.enqueue(a);
//				pila.pop();
//			}
//			pila.push(a[0]);
//		}
//		cola.dequeue();
//	}
//	while (!pila.empty()) {
//		// mete a la cola TODO lo que le resta a la pila
//		// hay momentos donde quedan '(' "perdidos"
//		// este parentesis jode el proceso cuando se evalua
//		if (pila.top() != '(') {
//			string a(1, pila.top());
//			colaPosfija.enqueue(a);
//		}
//		pila.pop();
//	}
//}

