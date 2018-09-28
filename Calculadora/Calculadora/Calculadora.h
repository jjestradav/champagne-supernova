#ifndef CALCULADORA_H
#define CALCULADORA_H

#include<string>
#include<iostream>
#include<cstdlib>
#include"QueueString.h"
#include"StackChar.h"
#include"StackDouble.h"

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
	void imprimirCola(QueueString& cola);
	bool esNumero(string numero);
	int precedencia(char c);
	void convertirPosfija(QueueString& cola);
	double operacion(char, double, double);
	double evaluarPosfija(QueueString& colaPosfija);
	string corregirExpresion(string expresion);
	void convertirAColaV2(string expresion);
private:
	QueueString cola;
	QueueString colaPosfija;
	QueueString colaImprimir;
};

#endif

