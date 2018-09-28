#pragma once
#include<iostream>
#include<string>
#include<sstream>
#include"StackInt.h"
#include"QueueString.h"

int decToBin(int dec);
int decToOct(int dec);
std::string decToHex(int dec);
int hexToDec(std::string s);
int octToDec(int s);
int binToDec(int s);
bool esNumeroHex(char s);

