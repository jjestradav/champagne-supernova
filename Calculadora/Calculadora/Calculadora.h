#ifndef CALCULADORA_H
#define CALCULADORA_H

#include<string>
#include<iostream>
#include<cstdlib>
#include"queue.h"
#include"Stack.h"

using std::istream;
using std::string;
using std::cin;
using std::cout;
using std::endl;

class Calculadora {
public:
	Calculadora();
	~Calculadora();
	void calcular();
	string capturarExpresion(istream&);
	void convertirACola(string expresion);
	void imprimirCola(queue<string>& cola);
	bool esNumero(string numero);
	int precedencia(char c);
	void convertirPosfija(queue<string>& cola);
private:
	queue<string> cola;
	queue<string> colaPosfija;
};

#endif

