#include "CambioDeBase.h"
int hexToDec(std::string s)
{
	std::stringstream ss;
	ss << std::hex << s;
	int aux;
	ss >> aux;
	return aux;

}

int octToDec(int s)
{
	std::stringstream ss;
	ss << std::oct << s;
	int aux;
	ss >> aux;
	return aux;
}

int binToDec(int s)
{
	int copia = s;
	if (s < 0) {
		s *= -1;
	}
	int exp = 0;
	int aux1 = 0;
	int aux2 = 0;
	int base = 1;
	std::string aux = "";
	while (s > 0) {
		aux1 = s % 10;
		aux2 += (aux1 * base);
		base *= 2;
		s /= 10;

	}
	if (copia < 0) {
		return aux2 * -1;
	}
	return aux2;
}

std::string decToHex(int dec)
{
	std::stringstream ss;
	ss << std::hex << dec;
	return ss.str();

}
int decToBin(int dec)
{
	StackInt stack;
	int copia = dec;
	if (dec < 0) {
		dec *= -1;
	}
	while (dec != 0) {


		int a = dec % 2;
		stack.push(a);

		dec = (int)(dec / 2);
	}

	std::stringstream ss;

	while (!stack.isEmpty()) {

		ss << stack.pop();
	
	}
	if (copia < 0) {
		return atoi(ss.str().c_str())*-1;
	}
	return atoi(ss.str().c_str());
}

int decToOct(int dec)
{
	StackInt stack;
	int copia = dec;
	if (dec < 0) {
		dec *= -1;
	}
	while (dec != 0) {


		int a = dec % 8;
		stack.push(a);

		dec = (int)(dec / 8);
	}

	std::stringstream ss;

	while (!stack.isEmpty()) {

		ss << stack.pop();
		
	}
	if (copia < 0) {
		return atoi(ss.str().c_str())*-1;
	}
	return atoi(ss.str().c_str());
}

bool esNumeroHex(char numero)
{

	if (!isdigit(numero)) {
		char aux = tolower(numero);
		if (aux != 'a' && aux != 'b'&& aux != 'c' && aux != 'd' && aux != 'e' && aux != 'f')
			return false;
	}
	return true;

}