#include "Calculadora.h"

Calculadora::Calculadora() {
}

Calculadora::~Calculadora() { }

void Calculadora::calcular() {
	string expresion = capturarExpresion(cin);
	expresion = corregirExpresion(expresion);
	convertirAColaV2(expresion);
	convertirPosfija(cola);
	double resultado = evaluarPosfija(colaPosfija);
	imprimirCola(colaImprimir);
	cout << "Resultado: " << resultado << endl;
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
		if (esNumero(string(1, expresion[i]))) {
			numTemp.append(1, expresion[i]);
			bandera = true;
		}
		else {
			if (bandera)
				cola.enqueue(string(numTemp));
			numTemp = "";
			bandera = false;
			string a(1, expresion[i]);
			cola.enqueue(a);
		}
	}
	if (bandera) // durante el for inserta solamente si se encuentra con un operando
		cola.enqueue(string(numTemp));
}

void Calculadora::imprimirCola(QueueString& cola) {
	while (!cola.isEmpty()) 
		cout << cola.dequeue() << ", ";
}

bool Calculadora::esNumero(string numero) {
	return ((atoi(numero.c_str())) || numero == "0");
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


void Calculadora::convertirPosfija(QueueString& cola) {
	char c;
	string a;
	StackChar pila;

	while (!cola.isEmpty()) {
		a = cola.next();
		if (esNumero(a))
			colaPosfija.enqueue(a);
		else if (a[0] == '(')
			pila.push(a[0]);
		else if (a[0] == ')')
			while ((c = pila.pop()) != '(') {
				string a(1, c);
				colaPosfija.enqueue(a);
			}
		else {
			while (!pila.isEmpty() && precedencia(pila.peek()) >= precedencia(a[0])) {
				string a(1, pila.pop());
				colaPosfija.enqueue(a);
			}
			pila.push(a[0]);
		}
		cola.dequeue();
	}
	while (!pila.isEmpty()) {
		// mete a la cola TODO lo que le resta a la pila
		// hay momentos donde quedan '(' "perdidos"
		// este parentesis jode el proceso cuando se evalua
		if (pila.peek() != '(') {
			string a(1, pila.peek());
			colaPosfija.enqueue(a);
		}
		pila.pop();
	}
}

double Calculadora::operacion(char operador, double val1, double val2) {
	switch (operador) {
	case '+': return (val1 + val2);
	case '-': return (val1 - val2);
	case '*': return (val1 * val2);
	case '/': return (val1 / val2);
	default: return 0;
	}
}

double Calculadora::evaluarPosfija(QueueString& colaPosfija) {
	StackDouble pila;
	string c;
	double oper1, oper2, valor;
	while (!colaPosfija.isEmpty()) {
		c = colaPosfija.next();
		if (esNumero(c)) {
			pila.push(atof(c.c_str()));
		}
		else {
			oper2 = pila.peek();
			pila.pop();
			oper1 = pila.peek();
			pila.pop();
			valor = operacion(c[0], oper1, oper2);
			pila.push(valor);
		}
		colaImprimir.enqueue(c);
		colaPosfija.dequeue();
	}
	return (pila.peek());
}

string Calculadora::corregirExpresion(string expresion) {
	string expLimpia;
	StackChar pilaExpresion;
	StackChar pilaSigno;

	for (std::string::size_type i = 0; i < expresion.size(); i++) {
		char valor = expresion[i];
		// caso 1: el valor es un numero
		if (esNumero(string(1, valor))) {
			// se realiza una operacion primero
			if (!pilaSigno.isEmpty()) {
				expLimpia += pilaSigno.peek();
				pilaExpresion.push(pilaSigno.peek());
			}
			expLimpia += valor;
			pilaExpresion.push(valor);

			if (!pilaSigno.isEmpty())
				pilaSigno.pop();
		}
		// caso 2: el valor es un operador
		else {
			// caso 2.1: que se vaya a realizar una nueva operacion
			if (pilaSigno.isEmpty())
				pilaSigno.push(valor);
			// caso 2.2: que sea 1--2
			else if (pilaSigno.peek() == '-' && valor == '-') {
				pilaSigno.pop();
				pilaSigno.push('+');
			}
			// caso 2.3: que sea 1+-2
			else if (pilaSigno.peek() == '+' && valor == '-') {
				pilaSigno.pop();
				pilaSigno.push('-');
			}
			else if ((pilaSigno.peek() != '-' && valor != '+') || (pilaSigno.peek() != '+' && valor != '+') || pilaSigno.peek() == ')') {
				expLimpia += pilaSigno.pop();
				pilaSigno.push(valor);
			}
		}
	}

	// pueden quedar unos parentesis locos por ahi
	while (!pilaSigno.isEmpty())
		expLimpia += pilaSigno.pop();

	return expLimpia;
}

void Calculadora::convertirAColaV2(string expresion) {
	string numTemp;
	QueueString colaSigno;
	bool bandera = false; // para controlar si lo primero y lo ultimo digitado es un entero

	for (size_t i = 0; i < expresion.size(); i++) {
		if (esNumero(string(1, expresion[i]))) {
			numTemp.append(1, expresion[i]);
			bandera = true;
		}
		else {
			colaSigno.enqueue(string(1, expresion[i]));

			if (bandera)
				cola.enqueue(numTemp);

			if (colaSigno.next() != "-" || bandera) {
				cola.enqueue(string(1, expresion[i]));
				colaSigno.dequeue();
				numTemp = "";
				bandera = false;
			}
			else {
				numTemp += "-";
				colaSigno.dequeue();
			}
		}
	}
	if (bandera) // durante el for inserta solamente si se encuentra con un operando
		cola.enqueue(numTemp);
}

int Calculadora::evaluarBase(size_t base)
{
	int a = 0;
	int b = 0;
	size_t aux = 0;
	int resultado = -1;
	StackChar stack;
	while (!cola.isEmpty()) {
		b = a;
		string d = cola.next();
		if (esNumero(d)) {

			switch (base) {
			case 2:
			{
				a = binToDec(atoi(d.c_str()));
			}
			break;

			case 8:
			{
				a = octToDec(atoi(d.c_str()));
			}

			break;

			default:
				break;
			}

			cola.dequeue();

			while (!stack.isEmpty()) {
				switch (base) {
				case 2:
				{

					if (resultado != -1) {
						resultado = operacion(stack.peek(), binToDec(resultado), a);
						resultado = decToBin(resultado);
					}
					else {
						resultado = operacion(stack.peek(), b, a);
						resultado = decToBin(resultado);
					}


					stack.pop();
				}
				break;

				case 8:
				{
					if (resultado != -1) {
						resultado = operacion(stack.peek(), octToDec(resultado), a);
						resultado = decToBin(resultado);
					}
					else {
						resultado = operacion(stack.peek(), b, a);
						resultado = decToOct(resultado);
					}


					stack.pop();
				}

				break;


				default:
					break;
				}

			}
		}
		else
		{
			stack.push(cola.dequeue()[0]);
			
		}
	}
	return resultado;
}

std::string Calculadora::evaluarHex()
{
	int a = 0;
	int b = 0;
	StackChar stack;
	int resultado = -1;

	while (!cola.isEmpty()) {

		if (esNumeroHex(cola.next()[0])) {
			b = a;
			a = hexToDec(cola.next());

			cola.dequeue();

			while (!stack.isEmpty()) {
				if (resultado != -1) {
					resultado = operacion(stack.peek(), resultado, a);

				}
				else {
					resultado = operacion(stack.peek(), b, a);

				}
				stack.pop();
			}
		}
		else {
			stack.push(cola.dequeue()[0]);
			
		}


	}
	return decToHex(resultado);
}
