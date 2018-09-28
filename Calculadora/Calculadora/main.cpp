/**<members>Nota: revisar el procedimiento cuando son numeros negativos, por ejemplo -3+-5</members>*/

#include <iostream>
#include<string>
#include<cstdlib>
#include<queue>
#include<stack>
#include"Calculadora.h"


istream& capturarExpresion(istream&, string&);
void convertirACola(string expresion, std::queue<string>& cola);
void imprimirCola(std::queue<string> cola);
bool esNumero(string numero);
std::queue<string> convertirPosfija(std::queue<string> cola);
int precedencia(char c);
double operacion(char, double, double);
double evaluarPosfija(std::queue<string> colaPosfija);

int main() {

	Calculadora calculadora;
	calculadora.calcular();
	system("pause");

	return 0;
}

double evaluarPosfija(std::queue<string> cola) {
	std::stack<double> pila;
	string c;
	double oper1, oper2, valor;
	while (!cola.empty()) {
		c = cola.front();
		if (esNumero(c)) {
			pila.push(atof(c.c_str()));
		}
		else {
			oper2 = pila.top();
			pila.pop();
			oper1 = pila.top();
			pila.pop();
			valor = operacion(c[0], oper1, oper2);
			pila.push(valor);
		}
		cola.pop();
	}
	return (pila.top());
}

double operacion(char operador, double val1, double val2) {
	switch (operador) {
	case '+': return (val1 + val2);
	case '-': return (val1 - val2);
	case '*': return (val1 * val2);
	case '/': return (val1 / val2);
	default: return 0;
	}
}

int precedencia(char c) {
	if (c == '(')
		return 1;
	if (c == '+' || c == '-')
		return 2;
	if (c == '*' || c == '/')
		return 3;
	return -1;
}

std::queue<string> convertirPosfija(std::queue<string> cola) {
	char c;
	string a;
	std::queue<string> temp;
	std::stack<char> pila;

	while (!cola.empty()) {
		a = cola.front();
		if (esNumero(a))
			temp.push(a);
		else if (a[0] == '(')
			pila.push(a[0]);
		else if (a[0] == ')')
			while ((c = pila.top()) != '(') {
				pila.pop();
				temp.push(string(1, c));
			}
		else {
			while (!pila.empty() && precedencia(pila.top()) >= precedencia(a[0])) {
				temp.push(string(1, pila.top()));
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
		if(pila.top() != '(')
			temp.push(string(1, pila.top()));
		pila.pop();
	}
	return temp;
}

bool esNumero(string numero) {
	for (size_t i = 0; i < numero.size(); i++) {
		if (!isdigit(numero[i]))
			return false;
	}
	return true;
}

void imprimirCola(std::queue<string> cola) {
	while (!cola.empty()) {
		cout << cola.front() << ", ";
		cola.pop();
	}
}

istream& capturarExpresion(istream& entrada, string& exp) {
	std::cout << "Digite una expresion interfija y presione <ENTER>: " << std::endl;

	if (entrada) {
		exp.clear();
		getline(entrada, exp);

		entrada.clear();
	}
	return entrada;
}
/**<idea>
	La idea del metodo es sustituir los caracteres que usabamos para realizar
	operaciones por string. Antes revisabamos caracter por caracter pero cuando
	son numeros superiores a 9 no funciona, por lo que se implementa una cola que
	tiene el proposito de almacenar los numeros y operandos en el mismo orden que
	fueron digitados para luego ser evaluados en el orden que corresponda, FIFO
	</idea>
*/
void convertirACola(string expresion, std::queue<string>& cola) {
	string numTemp;
	bool bandera = false; // para controlar si lo primero y lo ultimo digitado es un entero
	for (size_t i = 0; i < expresion.size(); i++) {
		if (isdigit(expresion[i])) {
			numTemp.append(1, expresion[i]);
			bandera = true;
		}
		else {
			if (bandera)
				cola.push(numTemp);
			numTemp = "";
			bandera = false;
			cola.push(string(1, expresion[i]));
		}
	}
	if (bandera) // durante el for inserta solamente si se encuentra con un operando
		cola.push(numTemp);
}